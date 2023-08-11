#include <iostream>

using namespace std;

class A
{
private:
	int m_x;
	
public:
	A(int x)
		: m_x(x)
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	/*B(int x)
		: A(x)
	{}*/

	B(int x) try : A(x) // ���� function-try�� ���� �ȴٸ�, �̷� ������ initialization list���� �������� ���ܸ� ���� �� ���δٰ� ��
	{
		// do initialization
	}
	catch (...)
	{
		cout << "Catch in B constructor" << endl;
		//throw; throw�� ������ �ִ� ��ó�� �۵��Ѵ�, �ּ� ó���ص�, ��ġ �ִ� ��ó�� �۵��� <- �����ڿ� function-try�� ����ϸ� ����� Ư¡
	}
};

void doSomething() // �̷� ������ �߰�ȣ�� �������� indenting�� �پ�� ����� function-try��� �Ѵ�, ���� �� ���δٰ� ��
try
{
	throw - 1;
}
catch (...)
{
	cout << "Catch in doSomething()" << endl;
}

int main()
{
	try
	{
		//doSomething();
		B b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}

	return 0;
}