#include <iostream>

using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	virtual ~Derived() override // virtual이 붙었을 때는 override가 문제없이 된다
	// virtual이 안 붙으면, 이름이 달라서 override가 안 된다, 어찌보면 당연한 얘기
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

int main()
{
	//Derived derived(5);

	Derived* derived = new Derived(5);
	Base* base = derived;
	delete base; // 다형성의 장점을 이용해서, 지울 때도
	// 상위타입의 포인터에 넣어서 지우는 것이 일반적이라고 함
	// 다만 이 경우, 하위타입의 소멸자가 실행이 안 되기 때문에, 메모리 누수가 발생할 수 있는데
	// 이걸 방지하려면, 소멸자에 virtual을 넣어주면 된다

	return 0;
}