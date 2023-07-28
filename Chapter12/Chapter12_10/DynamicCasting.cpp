#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm Derived 1" << endl;
	}
};

class Derived2 : public Base
{
public:
	std::string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm Derived 2" << endl;
	}
};

int main()
{
	Derived1 d1;
	Base* base = &d1;
	//base->m_j; // 안 됨
	d1.m_j = 2048;

	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	cout << base_to_d1->m_j << endl; // 잘 됨
	base_to_d1->m_j = 256;
	cout << d1.m_j << endl;

	auto* base_to_d2 = dynamic_cast<Derived2*>(base); // d1을 강제로 바꿔봄
	// dynamic_cast는 캐스팅(형변환)에 실패하면 nullptr을 넣어버린다
	// static_cast를 쓰면, 또 되긴 된다;;; 대신 런타임에 에러 체크를 안 한다
	// 그래서 어떤 경우에는 안 돼야 하는 것도 돼버림(무조건 밀어붙임) <- static_cast의 단점?
	// dynamic_cast는 에러 체크를 해주기 때문에, 런타임 중에 문제가 생길 때 잡아줄 수가 있다

	// 그래서 보통 dynamic_cast를 사용할 때는 if문과 함께 씀
	if (base_to_d2 != nullptr)
		cout << base_to_d2->m_name << endl; // 아무것도 안 나옴
	else
		cout << "Failed" << endl;

	return 0;
}