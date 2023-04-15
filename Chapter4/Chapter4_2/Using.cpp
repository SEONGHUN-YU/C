#include <iostream>

// ������ �Լ��� �̸��� ���� �� �����Ϸ��� ������ ����ϴ��� �𸣰ڴٰ�
// �Ҹ��� ����ϰ� �Ǵµ� �̰��� Ambiguity(��ȣ��)�̶�� �Ѵ�
// �� ��, ��ȣ���� �ذ����ִ� ���� using�̶�� Ű�����

namespace a
{
	int my_var(10);
	int my_a(123);
	int count = 123123;
}

namespace b
{
	int my_var(20);
	int my_b(456);
}

int main()
{
	using namespace std;
	/*using std::cout; // �̷��� �κ������θ� ������ ���� �ֱ� �ϴ�
	using std::endl;*/

	// using namespace�� Ư�� ������� ���� ������ �־������
	// �� ����� include�ϴ� ��� cpp���Ͽ� ������ �ְ� �Ǿ������
	// => ���ù����� ������ �߻��� �� �ִ�
	// ���� unsing namespace�� ������ٴ�, �������̸� cpp���Ͽ� �ִ� ���� ����
	// �������� ����ϴ� �͸�ŭ�� ���ϴ� ���� ����

	{
		using namespace a;
		cout << my_var << endl;
		// cout << count << endl; // std���� count�� �ֱ� ������ ����
	}

	{
		using namespace b;
		cout << my_var << endl;
	}

	cout << a::my_var << endl;
	cout << b::my_var << endl;

	// cout << my_a << endl;
	// cout << my_b << endl;

	cout << "Hello " << endl;

	return 0;
}