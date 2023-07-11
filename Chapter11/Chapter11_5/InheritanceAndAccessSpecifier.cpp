#include <iostream>
using namespace std;

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

class Derived : private Base
{
public:
	Derived()
	{
		Base::m_public = 123; // this->�� �����ƴٰ� ���� ��, Base::�� ���̸� ������ �ǹ�, �̰͵� �����ƴٰ� ���� ��
		Base::m_protected = 123; // Base::�� ���̴� �� �����ϰ� ���� ���� ���ٰ� ��, �򰥸��� �ʾƼ��ΰ�?
		//Base::m_private = 123; // error
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		//Derived::m_public = 1024; 
		// Derived���� Base�� private���� ��ӹ�����,
		// Derived���� ���̴�, Base���� �͵��� private�� ��ó�� �۵��Ѵ�
		// �׷��� ������ �ٴܻ���� �� ��, �� �������� �� ����
	}
};

int main()
{
	Base base;

	base.m_public = 123;
	/*base.m_protected = 123; // error
	base.m_private = 123;*/ // error

	Derived derived;
	//derived.m_public = 1024; // protected�� ��ӹ�����, public ����������� class�ۿ��� ���� ���ϰ� ��
	/*derived.m_protected = 1024; // ��� �޾Ƶ� �翬�� �� ��, �翬�� ���������� �׳� ��������� ���ܵ�
	derived.m_private = 1024;*/

	return 0;
}