#include <iostream>

using namespace std;

class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) { m_digit = digit; }

	// prefix : ++i
	Digit& operator++ ()
	{
		++m_digit;
		return *this;
	}
	Digit& operator-- ()
	{
		--m_digit;
		return *this;
	}

	// postfix : i++
	Digit operator++ (int) // parameter에 더미로 아무거나 넣으면 postfix로 간주한다
	{
		Digit temp(m_digit);
		++(*this); // 위에 미리 만들어둔 prefix를 활용한 것
		// ++m_digit; 안 만들어뒀으면 이렇게 구현
		return temp;
	}
	Digit operator-- (int)
	{
		Digit temp(m_digit);
		--m_digit;
		return temp;
	}

	friend std::ostream& operator<< (std::ostream& out, const Digit& d)
	{
		out << d.m_digit;
		return out;
	}
};

int main()
{
	Digit d(5);
	cout << ++d << endl;
	cout << d << endl;
	cout << d++ << endl;
	cout << d << endl;

	return 0;
}