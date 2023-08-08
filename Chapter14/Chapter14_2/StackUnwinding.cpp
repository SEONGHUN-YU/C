#include <iostream>

using namespace std;

// void last() throw(int) exception specifier
// void last() throw(...) exception specifier

void last() throw() // 예외를 안 던진다고 표시한 거, 애초에 exception specifier 자체가 잘 안 쓰인다고 함
{
	cout << "Last" << endl;
	cout << "Throws exception" << endl;
	
	throw - 1;
	
	cout << "End last" << endl; // 무시됨
}

void third() throw(int) // int에 대한 예외를 던진다고 표시한 거
						// 다만, 내부적으로 throw(...)으로 작동해서 큰 의미는 없고, 잘 안 쓰임
{
	cout << "Third" << endl;

	last();

	cout << "End third" << endl; // stack unwinding에 의해 무시됨
}

void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double) // catch가 있음에도 타입이 달라서 stack unwinding이 됨
	{
		cerr << "Second caught double exception" << endl; // 위의 이유로 무시됨
	}

	cout << "End second" << endl; // 마찬가지
}

void first()
{
	cout << "First" << endl;

	try
	{
		second();
	}
	catch (int) // 타입이 같아서 throw가 잡힘
	{
		cerr << "First caught int exception" << endl;
	}

	cout << "End first" << endl;
}

int main()
{
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "Main caught int exception" << endl;
	}

	// uncaught exceptions
	catch (...) // catch-all handlers
	{
		cerr << "main caught ellipses exception" << endl;
	}

	cout << "End main" << endl;

	return 0;
}