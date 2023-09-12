#include <iostream>
#include <thread>
#include <future> // async, future, promise 등을 사용할 수 있음

using namespace std;

int main()
{
	// multi-threading : 좀 옛날 방식
	{
		int result;
		std::thread t([&] { result = 1 + 2; });
		t.join();
		cout << result << endl;
	}

	// task-based parallelism : 주류
	{
		// std::future<int> fut = ...
		auto fut = std::async([] { return 1 + 2; }); // 비동기적
		cout << fut.get() << endl; // 작업을 마치고 값을 return 해줄 때까지 기다림, 비동기적으로 나중에 실행됨
	}

	// future and promise : multi-thread 사용하는 코드에 꽤 자주 나온다고 함, 개념은 알아두자
	{
		std::promise<int> prom; // future는 thread에서도 사용할 수 있는데, thread에서 사용하려면
		// promise라는 걸 미리 선언해줘야 한다
		auto fut = prom.get_future();

		auto t = std::thread([](std::promise<int>&& prom) // promise를 parameter에 넣어준 것
			{
				prom.set_value(1 + 2);
			}, std::move(prom));
		
		cout << fut.get() << endl; // set_value가 제대로 되어서 값이 넣어질 때까지 계속 기다림, 비동기적임
		t.join(); // thread는 thread대로 기다려줘야 함, join 위치는 크게 상관 없음
	}

	{
		auto f1 = std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});

		auto f2 = std::async([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		cout << "Main function" << endl; // 비동기적이라 가장 먼저 나옴
		// thread로 하면 가장 먼저 나오지 않음, async와 다르게 동작한다
		// thread와 async의 중요한 차이점 중 하나는
		// async는 소멸자가 끝나는 걸 대기를 해준다는 점이다
		// thread는 .join()으로 수동으로 기다려줘야 함
	}

	return 0;
}