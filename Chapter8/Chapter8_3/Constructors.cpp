#include <iostream>

using namespace std;

class Fraction // �м�
{
private:
	int m_numerator; // ����
	int m_denominator; // �и�

public:
	// �����ڸ� �� �����, �����Ϸ��� default constructor�� �˾Ƽ� ������ش� (Java�� ��������)
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
	Second sec; // ���� ȣ���

public:
	First()
	{
		cout << "class First constructor()" << endl;
	}

};

int main()
{
	Fraction frac; // ������ �ʰ� ���ÿ� �����ڰ� ������ �ȴ�
	// �������� parameter�� ���� ��쿡�� ���� ������, ������ () ���̷� �ϸ� ����, Ư���ϰ� �����̶�� ����?
	frac.print();
	
	// ��κ��� ���� 2���� ���� ���������
	Fraction one_thirds{ 1,3 }; // Ÿ�Ժ�ȯ�� ��� �� ��, �� �ֱٿ� ���� ����
	//Fraction one_thirds(1, 3); // warning�� ������ �������� �ȴ�
	one_thirds.print();

	First fir;

	return 0;
}