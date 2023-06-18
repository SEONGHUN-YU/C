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

	// =, [], (), -> �� 4���� ��.��.��! ����Լ��θ� ������ �����ε��� ������
	// [] : ���꽺ũ��Ʈ ��� �θ�
	// () : ����� �̶�� �θ�
	Cents operator+(const Cents& c2) // �ٲ� �� ���, ����Լ��� ������ �����ε�
	{
		return Cents(this->m_cents + c2.m_cents);
	}
};
/*friend Cents operator +(const Cents& c1, const Cents& c2) // �ٲٱ� �� ���, friend�Լ��� ������ �����ε�
{
	return Cents(c1.getCents() + c2.getCents());
}*/


/*Cents operator +(const Cents& c1, const Cents& c2) // ���� return �ϴ� ���� ���, �Ϲ��Լ��� ������ �����ε�
{
	return Cents(c1.getCents() + c2.getCents());
}*/

/*void add(const Cents& c1, const Cents& c2, Cents& c_out) // ���� ���
{
	c_out.getCents() = c1.getCents() + c2.getCents();
	// void�� ������ �̿��� ���� return ���
	// �������� ���� ���Ǿ��µ�, ������ �̷��� �� �� �Ѵٰ� ��
}*/
/*Cents sum_result;
add(cents1, cents2, sum_result);
cout << sum_result.getCents() << endl;*/

int main()
{
	Cents cents1(6);
	Cents cents2(8);
	cout << (cents1 + cents2 + Cents(6) + Cents(10) + Cents(100)).getCents() << endl;


	// ?:, ::, sizeof, ., .* �̷��� 5���� ������ �����ε��� �� ��
	// ���� ������, ���� ������, sizeof, ���������, �����ͼ�����
	// ^ <- �켱������ �ſ� ���� ��, �̷��� �켱������ ���� �͵��� ������ �����ε��� �� �ϴ� �� ����

	return 0;
}