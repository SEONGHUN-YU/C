#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm Derived 1" << endl;
	}
};

class Derived2 : public Base
{
public:
	std::string m_name = "Dr. Two";

	virtual void print() override
	{
		cout << "I'm Derived 2" << endl;
	}
};

int main()
{
	Derived1 d1;
	Base* base = &d1;
	//base->m_j; // �� ��
	d1.m_j = 2048;

	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	cout << base_to_d1->m_j << endl; // �� ��
	base_to_d1->m_j = 256;
	cout << d1.m_j << endl;

	auto* base_to_d2 = dynamic_cast<Derived2*>(base); // d1�� ������ �ٲ㺽
	// dynamic_cast�� ĳ����(����ȯ)�� �����ϸ� nullptr�� �־������
	// static_cast�� ����, �� �Ǳ� �ȴ�;;; ��� ��Ÿ�ӿ� ���� üũ�� �� �Ѵ�
	// �׷��� � ��쿡�� �� �ž� �ϴ� �͵� �Ź���(������ �о����) <- static_cast�� ����?
	// dynamic_cast�� ���� üũ�� ���ֱ� ������, ��Ÿ�� �߿� ������ ���� �� ����� ���� �ִ�

	// �׷��� ���� dynamic_cast�� ����� ���� if���� �Բ� ��
	if (base_to_d2 != nullptr)
		cout << base_to_d2->m_name << endl; // �ƹ��͵� �� ����
	else
		cout << "Failed" << endl;

	return 0;
}