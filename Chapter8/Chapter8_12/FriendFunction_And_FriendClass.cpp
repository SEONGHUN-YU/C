#include <iostream>

using namespace std;

class B; // forward declaration, ���� ����̱� �ѵ�
// B�� ���簡 ��� �ִ��� ã�ƾ��ϱ� ������, ������� ����, �ڵ� ���� �� ���������ٴ� ������ �ִ�
// ���⿡ ���� �� ���� ����� ������, ������ ���α׷� ���� ���� �� �� ���� ���ٰ� �Ѵ�
// �̰� ���� ����� �ֱ��ѵ�, ���ϰ� �Ǹ� �ڵ尡 �ʹ� �������� �� �ִٰ� ��
// �̷��ٺ��� �ε����ϰ� ���� ���α׷��ӵ��� ���� �ִٴ� ��
// ���� friend�� �� ��, �Բ� ���� ���δٴ� �� ����


class A
{
private:
	int m_value = 1;

	friend void doSomething(A& a, B& b);
};
class B
{
private:
	int m_value = 2;

	friend void doSomething(A& a, B& b);
};
void doSomething(A& a, B& b)
{
	cout << a.m_value << " " << b.m_value << endl;
}


class C
{
private:
	int m_value = 3;
	
	friend class D;
};
class D
{
private:
	int m_value = 4;

public:
	void doSomething(C& c)
	{
		cout << c.m_value << endl;
	}
};


class E;
class F
{
private:
	int m_value = 6;

public:
	void doSomething(E& e);
};
class E
{
private:
	int m_value = 5;

	//friend class F; ���� �Ļ���, �� ������ ���ѽ�Ų ����
	friend void F::doSomething(E& e);
};
void F::doSomething(E& e)
{
	cout << e.m_value << endl;
}

int main()
{
	A a;
	B b;
	doSomething(a, b);

	C c;
	D d;
	d.doSomething(c);

	E e;
	F f;
	f.doSomething(e);

	return 0;
}