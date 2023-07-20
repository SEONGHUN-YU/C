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
	virtual void print() { cout << "B" << endl; } // 사실 virtual은 최상위 클래스에서 1번만 써도 되지만
	// 나중에 디버깅할 때 편하기 위해, 가상함수를 오버라이딩한 것인지 아닌지 알기 쉽게하려는 용도로
	// 가상함수를 오버라이딩한 모든 함수에 virtual을 써주는 관습이 있다고 함
};

class C : public B
{
public:
	void print() { cout << "C" << endl; } // 일부러 virtual을 안 쓰겠음, 나중에 봤을 때 기억할 용도
};

class D : public C
{
public:
	void print() { cout << "D" << endl; }
	// 오버라이딩할 때는 항상, 가장 위에 있는 클래스가 기준이 된다
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

	// virtual function : 가상 함수
	// 가장 상위 클래스의 함수가 virtual이 되면 자식들이 virtual을 쓰지 않아도
	// 밑에 있는 함수들이 다 virtual처럼 작동한다

	return 0;
}