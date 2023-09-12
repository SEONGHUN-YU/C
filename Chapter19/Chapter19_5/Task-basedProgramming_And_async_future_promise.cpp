#include <iostream>
#include <thread>
#include <future> // async, future, promise ���� ����� �� ����

using namespace std;

int main()
{
	// multi-threading : �� ���� ���
	{
		int result;
		std::thread t([&] { result = 1 + 2; });
		t.join();
		cout << result << endl;
	}

	// task-based parallelism : �ַ�
	{
		// std::future<int> fut = ...
		auto fut = std::async([] { return 1 + 2; }); // �񵿱���
		cout << fut.get() << endl; // �۾��� ��ġ�� ���� return ���� ������ ��ٸ�, �񵿱������� ���߿� �����
	}

	// future and promise : multi-thread ����ϴ� �ڵ忡 �� ���� ���´ٰ� ��, ������ �˾Ƶ���
	{
		std::promise<int> prom; // future�� thread������ ����� �� �ִµ�, thread���� ����Ϸ���
		// promise��� �� �̸� ��������� �Ѵ�
		auto fut = prom.get_future();

		auto t = std::thread([](std::promise<int>&& prom) // promise�� parameter�� �־��� ��
			{
				prom.set_value(1 + 2);
			}, std::move(prom));
		
		cout << fut.get() << endl; // set_value�� ����� �Ǿ ���� �־��� ������ ��� ��ٸ�, �񵿱�����
		t.join(); // thread�� thread��� ��ٷ���� ��, join ��ġ�� ũ�� ��� ����
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

		cout << "Main function" << endl; // �񵿱����̶� ���� ���� ����
		// thread�� �ϸ� ���� ���� ������ ����, async�� �ٸ��� �����Ѵ�
		// thread�� async�� �߿��� ������ �� �ϳ���
		// async�� �Ҹ��ڰ� ������ �� ��⸦ ���شٴ� ���̴�
		// thread�� .join()���� �������� ��ٷ���� ��
	}

	return 0;
}