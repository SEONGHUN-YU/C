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
	Base b = d; // 객체 잘림, 다형성 사용이 불가능함(Base의 정보만 있음)

	b.print();
	doSomething(d);*/

	Base b;
	Derived d;

	std::vector<Base*> my_vec; // vector에는 ref&를 넣을 수가 없음, 포인터는 가능함
	my_vec.push_back(&b);
	my_vec.push_back(&d);

	for (auto& ele : my_vec) ele->print();

	std::vector<std::reference_wrapper<Base>> my_vec_ref; // ref로 넣을 수 있어짐
	my_vec_ref.push_back(b);
	my_vec_ref.push_back(d);

	for (auto& ele : my_vec_ref) ele.get().print(); // .get()은 ref를 return해주는 함수임

	return 0;
}