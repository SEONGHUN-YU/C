#include <iostream>

using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array exception" << endl;
	}
};

class MyArray
{
private:
	int m_data[5];

public:
	int& operator[] (const int& index)
	{
		//if (index < 0 || index >= 5) throw - 1; // 멤버함수 안에서도 throw를 할 수 있다
		if (index < 0 || index >= 5) throw ArrayException();
		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try {
		my_array[100]; // operator overloading된 상태
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	/*catch (ArrayException& e)
	{
		cout << "doSomething()" << endl;
		e.report();
		throw e;
	}*/
	catch (Exception& e)
	{
		cout << "doSomething()" << endl;
		e.report();
		//throw e; // 객체잘림으로 던진다
		throw; // 그대로 보내줌
		// rethrow한다고 함, step rewinding이 된다
	}
}

int main()
{
	try
	{
		doSomething();
	}
	catch (ArrayException& e) // throw; 일 때 받음
	{
		cout << "main()" << endl;
		e.report();
	}
	catch (Exception& e) // throw e; 일 때 받음
	{
		cout << "main()" << endl;
		e.report();
	}

	return 0;
}