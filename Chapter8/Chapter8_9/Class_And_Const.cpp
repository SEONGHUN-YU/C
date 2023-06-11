#include <iostream>
#include <string>

using namespace std;

class Something
{
public:
	int m_value = 0;

	Something(const Something& st_in) // ��ҿ��� ������ ����, �������� ��������
	{
		m_value = st_in.m_value;
		cout << "Copy Constructor" << endl;
	}

	Something()
	{
		cout << "Constructor" << endl;
	}

	void setValue(int value) { m_value = value; }
	int getValue() const { return m_value; } // instance�� const���, �Լ��� const�� �ٿ��� const {} �� �������� �Ѵ�
};

class Something_str
{
public:
	string m_value = "default";

	const string& getValue() const // const�� �ƴϳķ� overloading�� �ȴ�
	{
		cout << "const version" << endl;
		return m_value;
	}
	string& getValue()
	{
		cout << "non-const version" << endl;
		return m_value;
	}
};

void print(const Something& st)
{
	cout << &st << endl;
	cout << st.getValue() << endl; // st.m_value���� st.getValue()�� �� �����
}

int main()
{
	const Something something; // const�� ������ instance�� ������� ��� const�� ����� �Ͱ� ���ٰ� ���� �ȴ�
	//something.setValue(3); <- ����, �Ұ���
	cout << something.getValue() << endl;
	cout << &something << endl;
	print(something);

	Something_str something_str;
	something_str.getValue() = 10; // �� �ٲ��� �� ����
	const Something_str something_str2;
	something_str2.getValue(); // const���� �� �� �ٲ�

	return 0;
}

