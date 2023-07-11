#include <iostream>

using namespace std;

class Mother
{
private:
	int m_i;

public:
	Mother(const int& i_in = 0)
		: m_i(i_in)
	{
		cout << "Mother construction" << endl;
	}
};

class Child : public Mother
{
public:
	double m_d;

public:
	Child()
		: Mother(1024), m_d(1.0f)
	{
		cout << "Child construction" << endl;
	}
};

class A
{
public:
	A(int a)
	{
		cout << "A : " << a << endl;
	}

	~A()
	{
		cout << "Destructor A" << endl;
	}
};

class B : public A
{
public:
	B(int a, double b)
		: A(a)
	{
		cout << "B : " << b << endl;
	}

	~B()
	{
		cout << "Destructor B" << endl;
	}
};

class C : public B
{
public:
	C(int a, double b, char c)
		: B(a, b) // C 클래스에서 A()를 호출할 수는 없음
	{
		cout << "C : " << c << endl;
	}

	~C()
	{
		cout << "Destructor C" << endl;
	}
};

int main()
{
	Child c1;

	cout << sizeof(Mother) << endl;
	cout << sizeof(Child) << endl; // 패딩현상이 일어난다

	C c(1024, 3.14, 'a');

	return 0;
}