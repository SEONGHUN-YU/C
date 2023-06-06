#include <iostream>

using namespace std;

class Fraction // 분수
{
private:
	int m_numerator; // 분자
	int m_denominator; // 분모

public:
	// 생성자를 안 만들면, 컴파일러가 default constructor를 알아서 만들어준다 (Java와 마찬가지)
	Fraction(const int& num_in = 1, const int& den_in = 1)
	{
		m_numerator = num_in;
		m_denominator = den_in;
		cout << "Fraction() constructor" << endl;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

class Second
{
public:
	Second()
	{
		cout << "class Second constructor()" << endl;
	}
};

class First
{
	Second sec; // 먼저 호출됨

public:
	First()
	{
		cout << "class First constructor()" << endl;
	}

};

int main()
{
	Fraction frac; // 선언이 됨과 동시에 생성자가 실행이 된다
	// 생성자의 parameter가 없을 경우에만 생략 가능함, 억지로 () 붙이려 하면 에러, 특이하고 단점이라면 단점?
	frac.print();
	
	// 대부분의 경우는 2개가 거의 비슷하지만
	Fraction one_thirds{ 1,3 }; // 타입변환을 허용 안 함, 더 최근에 나온 문법
	//Fraction one_thirds(1, 3); // warning이 뜨지만 컴파일은 된다
	one_thirds.print();

	First fir;

	return 0;
}