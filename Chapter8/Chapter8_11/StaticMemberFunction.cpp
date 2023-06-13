#include <iostream>

using namespace std;

class Something
{
public:
	class _init // inner class : Ŭ���� �ȿ� Ŭ������ ���� �� ����
	{
	public:
		_init() // inner class�� �����ڸ� �̿��ؼ� Something�� static��������� �ʱ�ȭ��Ŵ
		{
			s_value = 9876;
		}
	};

private:
	static int s_value;
	int m_value;
	static _init s_initializer; // inner class�� static��������� ����� ��

public:
	Something() // static �����ڴ� ���� == static��������� �����ڿ��� �ʱ�ȭ �� �Ѵ�
		// �����ڸ� ���� ���� �ʱ�ȭ�� �� �� ������, innerŬ������ �̿��ؼ�
		// ��ȸ�ϴ� ������� ���������δ� �ʱ�ȭ�� �����ϴ�
		: m_value(123) //, s_value{ 2048 }; <- �Ұ���
	{}

	static int getValue()
	{
		return s_value;
		//return this->s_value; <- �Ұ���, static�Լ��� 'this->'�� �� �� ����
		// ��, this->�� �����ϴ� ��� �͵��� static�Լ������� �� �� ���ٴ� ��
	}
	int temp()
	{
		return this->s_value;
	}
};

int Something::s_value;
Something::_init Something::s_initializer; // �̰� inner class�� �����ڴ�

int main()
{
	cout << Something::getValue() << endl;
	//cout << Something::s_value << endl;
	Something s1, s2;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl; <- private�̶� ���� ���ϴµ�, getValue() ���� �ż� ������

	// instance s1�� s2�� �ּҴ� �ٸ�����, �Լ��� �ּҴ� ����
	int (Something:: * fptr1)() = &Something::temp;
	cout << (s2.*fptr1)() << endl;
	// s2��� instance�� �����͸� �Ѱ��ְ�, s2�� this->�� �����ٰ� �۵��ϴ� ����
	// non-static �Լ��� instance�� ������ �Ǿ� �־ instance ���̴� ������ �� �Ѵ�
	// ����, �� ��� s1 Ȥ�� s2 ���̴� �Լ������͸� ���� �Ұ���
	
	int (* fptr2)() = &Something::getValue; // static�Լ��� Ư�� instance�� ������� �����ų �� �ִ�
	// �׷��� ������ �����ͷ� ���� ���� ���ӽ����̽��� �ʿ����
	cout << fptr2() << endl;




	return 0;
}