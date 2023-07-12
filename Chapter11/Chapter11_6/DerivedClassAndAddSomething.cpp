#include <iostream>
using namespace std;

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value(value)
	{

	}


};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{

	}

	void setValue(int value)
	{
		Base::m_value = value;
		// do some work with the variables defined in Derived

		// 기본적으로는 부모클래스의 멤버변수는 private으로 만들고
		// getter나 setter등을 통해서 쓰는 게 일반적이고 당연한 건데
		// getter나 setter도 결국은 함수고, 함수를 한 번 거쳐야만
		// 접근할 수 있는 것이기 때문에, 퍼포먼스(속도)가 떨어질 수도 있고
		// 너무 빈번하게 쓰인다거나 하면, 코딩하는 게 번거로울 수도 있다
		// 그런 특수한 경우에는, 부모의 멤버변수를 protected로 해주는 것도
		// 방법이 될 수 있기 때문에, 참고용도로 남겨둔다
		// 다만 그렇게 사용할 일은 거의 없을 것 같다, private 쓰자
	}
};

int main()
{
	return 0;
}