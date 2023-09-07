#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx; // mutual exclusion : ��ȣ ���� == ���� �� �ǵ帮�� �Ѵ�

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

		t1.join(); // t1�� ���� ������ ��ٷ���
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
		// single thread�� �غ�
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
		// multi thread�� �غ�
		auto work_func = [](const string& name)
		{
			for (int i = 0; i < 5; ++i)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				
				mtx.lock(); // �ణ ��ũ�γ������� ����� ��
				cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
				mtx.unlock(); // ���ϴ� �۾��� �� ������ �ݵ�� Ǯ����� ��, �� �׷��� ����
			}
		};

		std::thread t1 = std::thread(work_func, "JackJack");
		std::thread t2 = std::thread(work_func, "Dash");

		t1.join();
		t2.join();
	}

	return 0;
}