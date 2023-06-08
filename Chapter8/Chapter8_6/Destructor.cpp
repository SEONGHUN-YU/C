#include <iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	}

	~Simple() // �Ҹ��� : instance�� ����� �� ȣ���� �Ǵ� �Լ�
	{
		cout << "Destructor " << m_id << endl;
	}
};

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];
		cout << "����" << endl;
	}

	~IntArray() // �Ҹ��ڴ� parameter�� ����
	{
		if (m_arr != nullptr) delete[] m_arr;
		cout << "�Ҹ�" << endl;
	}

	int size()
	{
		return m_length;
	}
};

int main()
{
	/*//Simple s1(0); // ���� �Ҵ�
	Simple* s1 = new Simple(0); // ���� �Ҵ�
	Simple s2(1);
	delete s1;*/

	int i = 0;
	while (true)
	{
		if (i == 10) break;
		IntArray my_int_arr(10);
		i++;
	}

	return 0;
}