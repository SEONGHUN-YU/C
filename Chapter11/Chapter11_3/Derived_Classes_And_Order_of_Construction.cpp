#include <iostream>

using namespace std;

class Mother
{
public:
	int m_i;

	/*Mother() 옛날에는, parameter 기본값 시스템이 없던 시절에는 이렇게 default 생성자를 일일이 구현했었다
		: m_i(0)
	{}*/

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
		: Mother(1024), m_d(1.0) // 적는 순서 상관없이, 무조건 부모의 생성자를 먼저 호출(실행)시킨다
	{
		/*this->m_i = 10; 부모의 멤버변수가 public일 떄 이런 식으로 접근 가능
		this->Mother::m_i = 1024;*/ // 위랑 똑같은 거임 public일 때만 가능, this->는 빼도 됨
		cout << "Child construction" << endl;
	}
};

class A
{
public:
	A()
	{
		cout << "A constructor" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B constructor" << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "C constructor" << endl;
	}
};

int main()
{
	Child c1;

	C c;

	return 0;
}