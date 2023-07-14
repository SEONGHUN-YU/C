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
		Base::print(); // 이렇게 하면 부모의 것도 실행됨
		cout << "I'm derived" << endl;
		//print(); 재귀호출이 되어버려서 infinite loop에 빠진다, 절대 Base:: 붙이지 않고는 쓰지말자
	}

	friend std::ostream& operator<< (std::ostream& out, const Derived& d)
	{
		cout << static_cast<Base>(d); // Base에서 연산자 오버로딩시킨 것을 이런 식으로 호출할 수 있음
		// Derived 클래스도 결국은 Base의 것을 메모리상으로 가지고 있기 때문에, 형변환이 된다는 듯
		// 부모 클래스에서 연산자 오버로딩시킨 것을 오버라이딩시킨 거라고 보면 된다
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