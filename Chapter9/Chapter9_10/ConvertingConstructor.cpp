#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(char) = delete; // 버젼업이 돼서, 예전에 쓰던 사람들이 예전 방식으로 못 쓰게 막을 때 등에 사용함
	// 그 외에도 auto converting 되거나 auto casting 되는 게 걱정이 되면 쓰기도 한다 함

	explicit Fraction(int num = 0, int den = 1) // explicit 키워드를 생성자 앞에 달아주면
		// 더 엄격해져서 converting constructor가 적용 안 됨 (의도한 것)
		: m_numerator{ num }, m_denominator{ den }
	{
		assert(den != 0);
	}

	Fraction(const Fraction& fraction) // copy constructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}

	friend std::ostream& operator<< (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " " << f.m_denominator << endl;
		return out;
	}
};

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	//doSomething(7); // converting constructor가 적용된 모습
	doSomething(Fraction()); // 기본값 시스템 응용 + explicit 때문에 직접 넣어줌
	// Fraction frac('c'); // delete 키워드에 의해 생성이 안 되는 모습

	return 0;
}