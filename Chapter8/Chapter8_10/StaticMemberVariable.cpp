#include <iostream>

using namespace std;

int generateID()
{
	static int s_id = 0;
	return ++s_id;
}

class Something
{
public:
	//static int m_value = 1; <- �� ��
	static int s_value; // static ��������� �ʱ�ȭ�� �� �� ����, ���� ����, �������� �ʱ�ȭ

	static constexpr int sc_value = 1; // static const ��������� �ݵ�� �ʱ�ȭ�ؾ� �ϰ�
	// �翬�� ��������, �������� �ʱ�ȭ�ϰų� ���Ҵ� �Ұ�����
};

int Something::s_value = 1; // define(�����ϴ�) in cpp, static ��������� cpp���� �ȿ� �����ϴ� �� ����
// ���Ǵ� �� ������ �ؾ� �Ѵٴ� ��Ģ�� ����Ǳ� ������, ������� �ȿ� �θ� ������ ������ �� ��

int main()
{
	cout << &Something::s_value << " " << Something::s_value << endl;
	Something st1;
	Something st2;
	st1.s_value = 2;
	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;
	Something::s_value = 1024;
	cout << &Something::s_value << " " << Something::s_value << endl;

	return 0;
}