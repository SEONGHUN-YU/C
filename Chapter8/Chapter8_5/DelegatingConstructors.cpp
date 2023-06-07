#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	int m_id;
	string m_name;

public:
	Student(const string& name_in)
		// : m_id(0), m_name(name_in) // �ſ� ����õ�ϴ� ���
		: Student(0, name_in) // ���� ������ : �����ڰ� �ٸ� �����ڸ� ����ϴ� ��
		// c++11���� ������
	{
	}

	Student(const int& id_in, const string& name_in)
		: m_id(id_in), m_name(name_in)
		// OOP ���踦 �� ��, ��� ����� �ϴ� �ڵ�� �� �������� ���;� �Ѵ�
		// �� ������ �����θ�, ������ ���� ���ϰ�, ������� ���� ��������
	{
	}

	void print()
	{
		cout << m_id << " " << m_name << endl;
	}

	/*Student(const string& name_in) // ���� ���, �����
	{
		init(0, name_in);
	}
	Student(const int& id_in, const string& name_in)
	{
		init(id_in, name_in);
	}
	void init(const int& id_in, const string& name_in) // ���� ������
	{
		m_id = id_in;
		m_name = name_in;
	}*/
};

int main()
{
	Student st1(0, "Jack Jack");
	st1.print();

	Student st2("Dash");
	st2.print();

	return 0;
}