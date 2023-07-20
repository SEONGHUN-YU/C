#include <iostream>

using namespace std;

class A
{
public:
	virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void print() { cout << "B" << endl; } // ��� virtual�� �ֻ��� Ŭ�������� 1���� �ᵵ ������
	// ���߿� ������� �� ���ϱ� ����, �����Լ��� �������̵��� ������ �ƴ��� �˱� �����Ϸ��� �뵵��
	// �����Լ��� �������̵��� ��� �Լ��� virtual�� ���ִ� ������ �ִٰ� ��
};

class C : public B
{
public:
	void print() { cout << "C" << endl; } // �Ϻη� virtual�� �� ������, ���߿� ���� �� ����� �뵵
};

class D : public C
{
public:
	void print() { cout << "D" << endl; }
	// �������̵��� ���� �׻�, ���� ���� �ִ� Ŭ������ ������ �ȴ�
};

int main()
{
	A a;
	a.print();
	
	B b;
	b.print();

	C c;
	c.print();

	D d;
	d.print();

	A& ref = b;
	ref.print();

	// virtual function : ���� �Լ�
	// ���� ���� Ŭ������ �Լ��� virtual�� �Ǹ� �ڽĵ��� virtual�� ���� �ʾƵ�
	// �ؿ� �ִ� �Լ����� �� virtualó�� �۵��Ѵ�

	return 0;
}