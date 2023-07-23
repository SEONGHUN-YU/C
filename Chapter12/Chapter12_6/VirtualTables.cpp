#include <iostream>

using namespace std;

class Base
{
public:
	//FunctionPointer *_vptr;
	virtual void func1() {};
	virtual void func2() {};
};

class Derived : public Base
{
public:
	//FunctionPointer *_vptr;
	virtual void func1() {};
	virtual void func3() {};
};

int main()
{
	cout << sizeof(Base) << endl;
	cout << sizeof(Derived) << endl;

	return 0;
}