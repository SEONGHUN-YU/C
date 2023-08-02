#include <iostream>
#include <array>
#include "Storage8.h"

using namespace std;

template<typename T>
class A
{
public:
	A(const T& input)
	{}

	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test()
	{}
};

template<>
class A<char> // ���� �ٸ� Ŭ���� �����ϴ� ���̶�� �����ص� ��
{
public:
	A(const char& temp)
	{}

	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}

	// �ֳ��ϸ� �����Ѹ�ŭ�� ����� �� ����, Ŭ�������� ���ٰ� ����̶� �򰥸��� �� ��
	// ���⿣ test()�� ��� ȣ���� �� ��, �ٸ� Ŭ������� ���� ������
};

int main()
{
	A<int> a_int(1); // �������� parameter�� ������ �� �ִ� ��쿡�� <int>�� �־ �ǰ� ��� �ȴ�, ���� �����ϴٴ� ��
	A<double> a_double(3.14); // �ٸ� c++17���� ������ �� �ִٴ� �� ����, ���� ���������� ������ ������ ��
	A<char> a_char('a');

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	// Define a Storage8 for integers
	Storage8<int> intStorage;
	for (int count = 0; count < 8; ++count)
		intStorage.set(count, count);
	for (int count = 0; count < 8; ++count)
		cout << intStorage.get(count) << '\n';
	cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << endl;

	// Define a Storage8 for bool
	Storage8<bool> boolStorage;
	for (int count = 0; count < 8; ++count)
		boolStorage.set(count, count & 3);
	for (int count = 0; count < 8; ++count)
		cout << (boolStorage.get(count) ? "true" : "false") << endl;
	cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << endl;

	return 0;
}