#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

atomic<int> shared_memory(0); // atomic�� ���� thread safe ��������, ��������
// �׷���, �˴� atomic���� ��������, �� �ʿ��� ������ ����

mutex mtx;

int main()
{
	{
		// atomic���� �ذ��� ���
		auto count_func = []() {
			for (int i = 0; i < 1000; ++i)
			{
				this_thread::sleep_for(chrono::milliseconds(1));
				shared_memory++;
				//shared_memory.fetch_add(1); ++�̶� ����
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
		// mutex�� �ذ��� ���
		auto count_func = []() {
			for (int i = 0; i < 1000; ++i)
			{
				this_thread::sleep_for(chrono::milliseconds(1));
				//mtx.lock();
				std::lock_guard<mutex> lock(mtx);
				//std::scoped_lock lock(mtx); c++17���� ��밡���� lock_guard�� ��ȭ��(�� �����ϴ� ��), template parameter �ڵ� �߷п� ���� <mutex>�� �����ص� ��
				shared_memory++;
				//mtx.unlock(); // .unlock()�� �� ���ָ� ���ù����� ���� �Ͼ�µ�
				// �׷� ��츦 �����ϱ� ���� lock_guard��� �� ����
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