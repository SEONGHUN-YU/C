#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

	/*Fraction(const Fraction& fraction) // 복사를 막아버리고 싶으면 private에서 오버로딩하면 된다
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}*/

public:
	Fraction(int num = 0, int den = 1)
		: m_numerator{ num }, m_denominator(1)
	{
		assert(den != 0);
	}

	Fraction(const Fraction& fraction) // 숨어있던 copy constructor를 오버로딩함, 초기화류에 작동함
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}

	friend std::ostream& operator<< (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};

Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << " func" << endl;
	return temp; // 반환값 최적화
	// 이 함수를 벗어나면 return 값인 temp가 유지가 될 필요가 없기 때문에
	// 컴파일러가 판단해서, copy constructor를 거치지 않고, 값만 직접 넣어서 초기화 시켜준 것
}

int main()
{
	Fraction frac(3, 5);
	Fraction copy = frac;
	cout << &frac << " " << &copy << endl;
	/*Fraction frac_copy = frac;
	Fraction frac_copy2(frac);
	Fraction frac_copy3{ frac };
	cout << frac << " " << frac_copy << endl;
	Fraction frac_except(Fraction(10, 20));*/ // 이 때는, copy constructor가 발동이 안 됨

	Fraction result = doSomething();
	cout << &result << endl;
	cout << result << endl;

	return 0;
}