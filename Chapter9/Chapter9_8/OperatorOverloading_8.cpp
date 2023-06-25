#include <iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }

	int getCents() { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	operator int() // ��ü�� ����ȯ�� �ʿ��� ��, �������� ����ȯ�� �� �����, instance�� �ٷ� �μ��� ���� �� � ����
	{
		cout << "cast here" << endl;
		return m_cents;
	}
};

class Dollars
{
private:
	int m_dollars = 0;

public:
	Dollars(const int& input) : m_dollars(input) {}

	operator Cents()
	{
		return Cents(m_dollars * 100);
	}
};

void printInt(const int& value)
{
	cout << value << endl;
}

int main()
{
	Cents cents(7);
	int value = (int)cents;
	value = int(cents);
	value = static_cast<int>(cents);
	printInt(cents);

	Dollars dol(2);
	Cents cents_dol = dol;
	printInt(cents_dol);

	return 0;
}