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
class A<char> // 거의 다른 클래스 구현하는 급이라고 생각해도 됨
{
public:
	A(const char& temp)
	{}

	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}

	// 왜냐하면 구현한만큼만 사용할 수 있음, 클래스명이 같다고 상속이랑 헷갈리면 안 됨
	// 여기엔 test()가 없어서 호출이 안 됨, 다른 클래스라고 봐도 무방함
};

int main()
{
	A<int> a_int(1); // 생성자의 parameter로 구분할 수 있는 경우에는 <int>가 있어도 되고 없어도 된다, 생략 가능하다는 뜻
	A<double> a_double(3.14); // 다만 c++17부터 생략할 수 있다는 것 같음, 하위 버젼에서는 컴파일 에러가 남
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