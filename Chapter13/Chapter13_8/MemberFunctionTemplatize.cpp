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

	template<typename TT> // doSomething에서만 쓸 수 있는 template 
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

	a_int.doSomething(char()); // 이런 식으로 instantiation을 구분해줄 수도 있음
	a_int.doSomething<float>(123); // <float>은 생략할 수 있음

	return 0;
}