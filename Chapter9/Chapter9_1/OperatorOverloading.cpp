#include <iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	// =, [], (), -> 이 4개는 반.드.시! 멤버함수로만 연산자 오버로딩이 가능함
	// [] : 서브스크립트 라고 부름
	// () : 펑션콜 이라고 부름
	Cents operator+(const Cents& c2) // 바꾼 후 모양, 멤버함수로 연산자 오버로딩
	{
		return Cents(this->m_cents + c2.m_cents);
	}
};
/*friend Cents operator +(const Cents& c1, const Cents& c2) // 바꾸기 전 모양, friend함수로 연산자 오버로딩
{
	return Cents(c1.getCents() + c2.getCents());
}*/


/*Cents operator +(const Cents& c1, const Cents& c2) // 직접 return 하는 요즘 방식, 일반함수로 연산자 오버로딩
{
	return Cents(c1.getCents() + c2.getCents());
}*/

/*void add(const Cents& c1, const Cents& c2, Cents& c_out) // 옛날 방식
{
	c_out.getCents() = c1.getCents() + c2.getCents();
	// void로 참조를 이용한 간접 return 방식
	// 예전에는 많이 사용되었는데, 요즘은 이렇게 잘 안 한다고 함
}*/
/*Cents sum_result;
add(cents1, cents2, sum_result);
cout << sum_result.getCents() << endl;*/

int main()
{
	Cents cents1(6);
	Cents cents2(8);
	cout << (cents1 + cents2 + Cents(6) + Cents(10) + Cents(100)).getCents() << endl;


	// ?:, ::, sizeof, ., .* 이렇게 5개는 연산자 오버로딩이 안 됨
	// 조건 연산자, 범위 연산자, sizeof, 멤버셀렉션, 포인터셀렉션
	// ^ <- 우선순위가 매우 낮은 편, 이렇게 우선순위가 낮은 것들은 연산자 오버로딩을 안 하는 게 낫다

	return 0;
}