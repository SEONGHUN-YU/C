#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

atomic<int> shared_memory(0); // atomic을 쓰면 thread safe 해지지만, 느려진다
// 그러니, 죄다 atomic으로 하지말고, 꼭 필요한 곳에만 쓰자

mutex mtx;

int main()
{
	{
		// atomic으로 해결한 방법
		auto count_func = []() {
			for (int i = 0; i < 1000; ++i)
			{
				this_thread::sleep_for(chrono::milliseconds(1));
				shared_memory++;
				//shared_memory.fetch_add(1); ++이랑 같음
			}
		};

		thread t1 = thread(count_func);
		thread t2 = thread(count_func);

		t1.join();
		t2.join();

		cout << "After" << endl;
		cout << shared_memory << endl;
	}

	{
		// mutex로 해결한 방법
		auto count_func = []() {
			for (int i = 0; i < 1000; ++i)
			{
				this_thread::sleep_for(chrono::milliseconds(1));
				//mtx.lock();
				std::lock_guard<mutex> lock(mtx);
				//std::scoped_lock lock(mtx); c++17부터 사용가능한 lock_guard의 강화판(더 안전하다 함), template parameter 자동 추론에 의해 <mutex>는 생략해도 됨
				shared_memory++;
				//mtx.unlock(); // .unlock()을 안 해주면 무시무시한 일이 일어나는데
				// 그런 경우를 방지하기 위해 lock_guard라는 게 있음
			}
		};

		thread t1 = thread(count_func);
		thread t2 = thread(count_func);

		t1.join();
		t2.join();

		cout << "After" << endl;
		cout << shared_memory << endl;
	}

	return 0;
}