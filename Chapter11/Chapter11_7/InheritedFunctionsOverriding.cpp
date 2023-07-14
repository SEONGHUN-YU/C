#include <iostream>

using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm base" << endl;
	}

	friend std::ostream& operator<< (std::ostream& out, const Base& b)
	{
		out << "This is base output" << endl;
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value, double d)
		: Base(value), m_d(d)
	{}

	void print()
	{
		Base::print(); // �̷��� �ϸ� �θ��� �͵� �����
		cout << "I'm derived" << endl;
		//print(); ���ȣ���� �Ǿ������ infinite loop�� ������, ���� Base:: ������ �ʰ�� ��������
	}

	friend std::ostream& operator<< (std::ostream& out, const Derived& d)
	{
		cout << static_cast<Base>(d); // Base���� ������ �����ε���Ų ���� �̷� ������ ȣ���� �� ����
		// Derived Ŭ������ �ᱹ�� Base�� ���� �޸𸮻����� ������ �ֱ� ������, ����ȯ�� �ȴٴ� ��
		// �θ� Ŭ�������� ������ �����ε���Ų ���� �������̵���Ų �Ŷ�� ���� �ȴ�
		out << "This is derived output" << endl;
		return out;
	}
};

int main()
{
	Base base(5);
	base.print();

	Derived derived(7, 1.0);
	derived.print();

	cout << base;
	cout << derived;

	return 0;
}