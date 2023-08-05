#include <iostream>

using namespace std;

template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		: m_value(input)
	{}

	template<typename TT> // doSomething������ �� �� �ִ� template 
	void doSomething(const TT& input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
	}

	void print()
	{
		cout << m_value << endl;
	}
};

int main()
{
	A<char> a_int('A');
	a_int.print();

	a_int.doSomething(char()); // �̷� ������ instantiation�� �������� ���� ����
	a_int.doSomething<float>(123); // <float>�� ������ �� ����

	return 0;
}