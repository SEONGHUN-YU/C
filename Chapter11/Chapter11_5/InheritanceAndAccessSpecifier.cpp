#include <iostream>
using namespace std;

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

class Derived : private Base
{
public:
	Derived()
	{
		Base::m_public = 123; // this->가 생략됐다고 보면 됨, Base::를 붙이면 강조의 의미, 이것도 생략됐다고 봐도 됨
		Base::m_protected = 123; // Base::를 붙이는 게 유용하게 쓰일 때가 많다고 함, 헷갈리지 않아서인가?
		//Base::m_private = 123; // error
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		//Derived::m_public = 1024; 
		// Derived에서 Base를 private으로 상속받으면,
		// Derived에서 쓰이던, Base들의 것들이 private인 것처럼 작동한다
		// 그렇기 때문에 다단상속을 할 때, 꽤 복잡해질 수 있음
	}
};

int main()
{
	Base base;

	base.m_public = 123;
	/*base.m_protected = 123; // error
	base.m_private = 123;*/ // error

	Derived derived;
	//derived.m_public = 1024; // protected로 상속받으면, public 멤버변수여도 class밖에서 접근 못하게 됨
	/*derived.m_protected = 1024; // 상속 받아도 당연히 안 됨, 당연한 내용이지만 그냥 참고용으로 남겨둠
	derived.m_private = 1024;*/

	return 0;
}