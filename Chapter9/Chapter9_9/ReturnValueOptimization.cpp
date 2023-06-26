#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

	/*Fraction(const Fraction& fraction) // ���縦 ���ƹ����� ������ private���� �����ε��ϸ� �ȴ�
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

	Fraction(const Fraction& fraction) // �����ִ� copy constructor�� �����ε���, �ʱ�ȭ���� �۵���
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
	return temp; // ��ȯ�� ����ȭ
	// �� �Լ��� ����� return ���� temp�� ������ �� �ʿ䰡 ���� ������
	// �����Ϸ��� �Ǵ��ؼ�, copy constructor�� ��ġ�� �ʰ�, ���� ���� �־ �ʱ�ȭ ������ ��
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
	Fraction frac_except(Fraction(10, 20));*/ // �� ����, copy constructor�� �ߵ��� �� ��

	Fraction result = doSomething();
	cout << &result << endl;
	cout << result << endl;

	return 0;
}