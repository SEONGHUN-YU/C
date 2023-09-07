#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx; // mutual exclusion : 상호 배제 == 서로 못 건드리게 한다

int main()
{
	/*{
		std::thread t1 = std::thread([]() {
			cout << std::this_thread::get_id() << endl;
			});
		std::thread t2 = std::thread([]() {
			cout << std::this_thread::get_id() << endl;
			});
		std::thread t3 = std::thread([]() {
			cout << std::this_thread::get_id() << endl;
			});
		std::thread t4 = std::thread([]() {
			cout << std::this_thread::get_id() << endl;
			});

		t1.join(); // t1이 끝날 때까지 기다려줌
		t2.join();
		t3.join();
		t4.join();
	}*/

	/*{
		const int num_pro = std::thread::hardware_concurrency();
		cout << std::this_thread::get_id() << endl;

		vector<std::thread> my_threads;
		my_threads.resize(num_pro);

		for (auto& e : my_threads)
			e = std::thread([]() {
			cout << std::this_thread::get_id() << endl;
				});

		for (auto& e : my_threads)
			e.join();
	}*/

	/*{
		// single thread로 해봄
		auto work_func = [](const string& name)
		{
			for (int i = 0; i < 5; ++i)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				cout << name << " " << std::this_thread::get_id() << " is working" << i << endl;
			}
		};

		work_func("JackJack");
		work_func("Dash");
	}*/

	{
		// multi thread로 해봄
		auto work_func = [](const string& name)
		{
			for (int i = 0; i < 5; ++i)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				
				mtx.lock(); // 약간 싱크로나이즈드랑 비슷한 듯
				cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
				mtx.unlock(); // 원하는 작업이 다 끝나면 반드시 풀어줘야 함, 안 그러면 에러
			}
		};

		std::thread t1 = std::thread(work_func, "JackJack");
		std::thread t2 = std::thread(work_func, "Dash");

		t1.join();
		t2.join();
	}

	return 0;
}