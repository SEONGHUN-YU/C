#include <iostream>

using namespace std;

int generateID()
{
	static int s_id = 0;
	return ++s_id;
}

class Something
{
public:
	//static int m_value = 1; <- 안 됨
	static int s_value; // static 멤버변수는 초기화를 할 수 없다, 선언만 가능, 전역에서 초기화

	static constexpr int sc_value = 1; // static const 멤버변수는 반드시 초기화해야 하고
	// 당연한 말이지만, 전역에서 초기화하거나 재할당 불가능함
};

int Something::s_value = 1; // define(정의하다) in cpp, static 멤버변수는 cpp파일 안에 정의하는 게 좋음
// 정의는 한 곳에만 해야 한다는 원칙에 위배되기 때문에, 헤더파일 안에 두면 컴파일 에러가 날 것

int main()
{
	cout << &Something::s_value << " " << Something::s_value << endl;
	Something st1;
	Something st2;
	st1.s_value = 2;
	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;
	Something::s_value = 1024;
	cout << &Something::s_value << " " << Something::s_value << endl;

	return 0;
}