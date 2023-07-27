#include <iostream>
#include <vector>
#include <functional>

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

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() override
	{
		cout << "I'm Derived" << endl;
	}
};

void doSomething(Base b)
{
	b.print();
}

int main()
{
	/*Derived d;
	Base b = d; // ��ü �߸�, ������ ����� �Ұ�����(Base�� ������ ����)

	b.print();
	doSomething(d);*/

	Base b;
	Derived d;

	std::vector<Base*> my_vec; // vector���� ref&�� ���� ���� ����, �����ʹ� ������
	my_vec.push_back(&b);
	my_vec.push_back(&d);

	for (auto& ele : my_vec) ele->print();

	std::vector<std::reference_wrapper<Base>> my_vec_ref; // ref�� ���� �� �־���
	my_vec_ref.push_back(b);
	my_vec_ref.push_back(d);

	for (auto& ele : my_vec_ref) ele.get().print(); // .get()�� ref�� return���ִ� �Լ���

	return 0;
}