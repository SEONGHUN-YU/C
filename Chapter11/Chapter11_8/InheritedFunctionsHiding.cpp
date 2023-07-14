#include <iostream>

using namespace std;

// ��� �޾ƿ� ���� ������� ���ϵ��� ���ƹ����� �� �������

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
};

class Derived : public Base
{
private:
	double m_d;

	//using Base::print; ����� ��� �ǰ�, �ؿ��� private ������ �ٽ� ���� ��� �ǰ�,
	// �̰� �������̶�� �Ѵ�, ������� �ڸ��� using�� �� ���� ���Ƽ� ���� ����� �ְ�, �پ��� �� ��

public:
	Derived(int value, double d)
		: Base(value), m_d(d)
	{}

	using Base::m_i; // public �������� �̷��� �����ϸ�, �θ𿡼� protected�� ������ ��������� public�� �Ǿ������

private:
	//using Base::print; // <- �� ���� ()�� ���̸� �� �ȴ�, private �������� �����߱� ������, �θ� Ŭ�������� public�̾��� print�Լ��� private�� �ȴ�
	// do not add ()

	void print() = delete; // �̷��Ե� �� �� �ִµ�, �̷��� �ڽ����δ� ���� ���ϰ� ��, using�� ���� ȿ��
};

int main()
{
	Derived derived(7, 1.0);

	derived.m_i = 1024; // using ���п� protected���� public���� ���Ͽ�, ���� ��������
	//derived.print(); // using ������ private�� �Ǿ�, ȣ���� �Ұ�������
	// ���漱�� = delete;�� ���� �����ε� ȣ���� �Ұ�������

	Base base(5);
	base.print();

	return 0;
}