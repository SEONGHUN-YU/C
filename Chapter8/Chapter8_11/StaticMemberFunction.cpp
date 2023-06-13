#include <iostream>

using namespace std;

class Something
{
public:
	class _init // inner class : 클래스 안에 클래스가 있을 수 있음
	{
	public:
		_init() // inner class의 생성자를 이용해서 Something의 static멤버변수를 초기화시킴
		{
			s_value = 9876;
		}
	};

private:
	static int s_value;
	int m_value;
	static _init s_initializer; // inner class를 static멤버변수로 만들어 줌

public:
	Something() // static 생성자는 없다 == static멤버변수는 생성자에서 초기화 못 한다
		// 생성자를 통해 직접 초기화는 할 수 없지만, inner클래스를 이용해서
		// 우회하는 방법으로 간접적으로는 초기화가 가능하다
		: m_value(123) //, s_value{ 2048 }; <- 불가능
	{}

	static int getValue()
	{
		return s_value;
		//return this->s_value; <- 불가능, static함수는 'this->'를 쓸 수 없다
		// 즉, this->로 접근하는 모든 것들을 static함수에서는 쓸 수 없다는 말
	}
	int temp()
	{
		return this->s_value;
	}
};

int Something::s_value;
Something::_init Something::s_initializer; // 이건 inner class의 생성자다

int main()
{
	cout << Something::getValue() << endl;
	//cout << Something::s_value << endl;
	Something s1, s2;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl; <- private이라서 접근 못하는데, getValue() 쓰면 돼서 괜찮음

	// instance s1과 s2의 주소는 다르지만, 함수의 주소는 같다
	int (Something:: * fptr1)() = &Something::temp;
	cout << (s2.*fptr1)() << endl;
	// s2라는 instance의 포인터를 넘겨주고, s2의 this->를 가져다가 작동하는 형태
	// non-static 함수는 instance에 종속이 되어 있어서 instance 없이는 실행을 못 한다
	// 따라서, 이 경우 s1 혹은 s2 없이는 함수포인터를 실행 불가능
	
	int (* fptr2)() = &Something::getValue; // static함수는 특정 instance와 상관없이 실행시킬 수 있다
	// 그렇기 때문에 포인터로 받을 때도 네임스페이스가 필요없다
	cout << fptr2() << endl;




	return 0;
}