#include <iostream>

using namespace std;

// 상속 받아온 것을 사용하지 못하도록 막아버리는 걸 배워보자

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

	//using Base::print; 여기다 적어도 되고, 밑에서 private 공간을 다시 만들어서 적어도 되고,
	// 이건 취향차이라고 한다, 멤버변수 자리에 using들 한 번에 몰아서 쓰는 사람도 있고, 다양한 듯 함

public:
	Derived(int value, double d)
		: Base(value), m_d(d)
	{}

	using Base::m_i; // public 공간에서 이렇게 선언하면, 부모에서 protected로 선언한 멤버변수도 public이 되어버린다

private:
	//using Base::print; // <- 이 때는 ()를 붙이면 안 된다, private 공간에서 선언했기 때문에, 부모 클래스에서 public이었던 print함수가 private이 된다
	// do not add ()

	void print() = delete; // 이렇게도 쓸 수 있는데, 이러면 자식으로는 접근 못하게 됨, using과 같은 효과
};

int main()
{
	Derived derived(7, 1.0);

	derived.m_i = 1024; // using 덕분에 protected에서 public으로 변하여, 접근 가능해짐
	//derived.print(); // using 때문에 private이 되어, 호출이 불가능해짐
	// 전방선언 = delete;를 쓰는 것으로도 호출이 불가능해짐

	Base base(5);
	base.print();

	return 0;
}