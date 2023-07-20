#include <iostream>

using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
	virtual A* getThis()
	{
		cout << "A::getThis()" << endl;
		return this;
	}
};

class B : public A
{
public:
	void print() { cout << "B" << endl; } // parameter�� �ٸ���, �������̵��� ���� ����
	// parameter�� �ٸ���, �����Ϸ��� �����ε����� �����ع���, �� A�� �Լ��� �����Ϸ��� �Ϸ������� �ϰ� A�� �Լ��� �����ϴ� ��
	// �̷� ��Ȳ�� �������� override Ű���带 �־��ָ� �����ϵǱ� ���� ����� �� �ִ�
	// final Ű���带 ����, ���� Ŭ�������� �������̵� �Ұ����ϰ� �ȴ�
	// final�� override�� �����Լ�(�Ǵ� �������̵��� �����Լ�)���� �� �� �ִ�

	virtual B* getThis()
	{
		cout << "B::getThis()" << endl;
		return this;
	}
	// ������ return Ÿ���� �ٸ��� �������̵��� �� �Ǵµ�
	// ��Ӱ��迩�� ������ return Ÿ���� �޶� �������̵��� �Ǵ� �� ����
	// �ٵ�, �����ϸ� B�� ������ �����ؼ� A�� �ּҸ� return�ϴ� ���̷����� ��Ȳ�� ������, �̷� ��
	// covariant return type : ���� ��ȯ�� <- ��� �ϴ� �� ����
};

class C : public B
{
public:
	//virtual void print(int x) { cout << "C" << endl; }
	// final ������ �������̵��� �� �Ǵ� ���
};

int main()
{
	A a;
	B b;
	//C c;

	A& ref = b;
	b.getThis()->print();
	ref.getThis()->print();

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;

	return 0;
}