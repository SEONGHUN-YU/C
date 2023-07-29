#include <iostream>

class Base
{
public:
	Base() {}

	friend std::ostream& operator<< (std::ostream& out, const Base& b)
		// friend function은 member function이 아님
		// 그래서 물려줄 수 없고, 오버라이딩이 안 됨
		// 엄밀히 말하자면, 직접적으로 오버라이딩은 안 되지만 간접적으로 오버라이딩시킬 수는 있음
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b;
	std::cout << b << '\n';

	Derived d;
	std::cout << d << '\n';
	// note that this works even with no operator<< that explicitly handles Derived

	Base& bref = d;
	std::cout << bref << '\n';

	return 0;
}