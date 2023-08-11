#include <iostream>

using namespace std;

class A
{
private:
	int m_x;
	
public:
	A(int x)
		: m_x(x)
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	/*B(int x)
		: A(x)
	{}*/

	B(int x) try : A(x) // 보통 function-try는 쓰게 된다면, 이런 식으로 initialization list에서 생성자의 예외를 잡을 때 쓰인다고 함
	{
		// do initialization
	}
	catch (...)
	{
		cout << "Catch in B constructor" << endl;
		//throw; throw가 없지만 있는 것처럼 작동한다, 주석 처리해도, 마치 있는 것처럼 작동함 <- 생성자에 function-try를 사용하면 생기는 특징
	}
};

void doSomething() // 이런 식으로 중괄호가 없어지고 indenting이 줄어든 모양을 function-try라고 한다, 거의 안 쓰인다고 함
try
{
	throw - 1;
}
catch (...)
{
	cout << "Catch in doSomething()" << endl;
}

int main()
{
	try
	{
		//doSomething();
		B b(0);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}

	return 0;
}