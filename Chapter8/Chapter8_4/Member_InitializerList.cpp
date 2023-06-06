#include <iostream>

using namespace std;

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in)
		: m_b(m_b_in)
	{
	}
};

class Something
{
private:
	int m_i = 123; // non-static ������� �ʱ�ȭ ������ �� ����
	double m_d;
	char m_c;
	int m_arr[5]; // c++11���� �迭�� �ʱ�ȭ ����
	B m_b;

public:
	Something()
		: m_i(1), m_d(3.14), m_c{ 'a' }, // member initializer list : ��� �ʱ�ȭ ����Ʈ
		m_arr{ 1,2,3,4,5 }, m_b(m_i - 1) // ()��� {}�� ��
		// ������� �ʱ�ȭ��, ��� �ʱ�ȭ ����Ʈ�� ���ÿ� ������ ����
		// ��� �ʱ�ȭ ����Ʈ�� �켱 �����
		// �� �Ŀ� ������ ������ �ٽ� �Ҵ��� ��ų ��� ���������� ������ ������ ���� ���� �����
	{
		m_i *= 1;
		m_d *= 3.0;
		m_c += 3; // �ʱ�ȭ ��Ű�� ���� �ƴϱ� ������ �̷� �� ����
	}

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& i : m_arr)
			cout << i << " ";
		cout << endl;
	}
};

int main()
{
	Something som;
	som.print();

	return 0;
}