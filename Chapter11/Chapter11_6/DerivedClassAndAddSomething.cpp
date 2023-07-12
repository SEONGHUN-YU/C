#include <iostream>
using namespace std;

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value(value)
	{

	}


};

class Derived : public Base
{
public:
	Derived(int value)
		: Base(value)
	{

	}

	void setValue(int value)
	{
		Base::m_value = value;
		// do some work with the variables defined in Derived

		// �⺻�����δ� �θ�Ŭ������ ��������� private���� �����
		// getter�� setter���� ���ؼ� ���� �� �Ϲ����̰� �翬�� �ǵ�
		// getter�� setter�� �ᱹ�� �Լ���, �Լ��� �� �� ���ľ߸�
		// ������ �� �ִ� ���̱� ������, �����ս�(�ӵ�)�� ������ ���� �ְ�
		// �ʹ� ����ϰ� ���δٰų� �ϸ�, �ڵ��ϴ� �� ���ŷο� ���� �ִ�
		// �׷� Ư���� ��쿡��, �θ��� ��������� protected�� ���ִ� �͵�
		// ����� �� �� �ֱ� ������, ����뵵�� ���ܵд�
		// �ٸ� �׷��� ����� ���� ���� ���� �� ����, private ����
	}
};

int main()
{
	return 0;
}