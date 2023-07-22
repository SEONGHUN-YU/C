#include <iostream>

using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	virtual ~Derived() override // virtual�� �پ��� ���� override�� �������� �ȴ�
	// virtual�� �� ������, �̸��� �޶� override�� �� �ȴ�, ����� �翬�� ���
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

int main()
{
	//Derived derived(5);

	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base; // �������� ������ �̿��ؼ�, ���� ����
	// ����Ÿ���� �����Ϳ� �־ ����� ���� �Ϲ����̶�� ��
	// �ٸ� �� ���, ����Ÿ���� �Ҹ��ڰ� ������ �� �Ǳ� ������, �޸� ������ �߻��� �� �ִµ�
	// �̰� �����Ϸ���, �Ҹ��ڿ� virtual�� �־��ָ� �ȴ�

	return 0;
}