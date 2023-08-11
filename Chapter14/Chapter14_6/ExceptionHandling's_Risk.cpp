#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	~A()
	{
		//throw "error"; // 소멸자 안에서 throw를 하는 짓은 절대 하지말 것, 금기시되는 일임
	} // 소멸자에서는 예외를 던지는 것 자체가 불가능 함
};

int main()
{
	try
	{
		int* i = new int[1000000];
		unique_ptr<int> up_i(i); // block(영역)을 벗어나면, unique 포인터가 알아서 메모리를 지워준다고 함
		// throw되더라도 마찬가지로 알아서 메모리를 지워줌 -> delete[] 안 해줘도 됨

		// do something with i
		throw "error";
		//delete[] i; // throw 때문에 memory leak이 생길 수 있음

		A a;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;
}