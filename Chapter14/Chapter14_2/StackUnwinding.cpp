#include <iostream>

using namespace std;

// void last() throw(int) exception specifier
// void last() throw(...) exception specifier

void last() throw() // ���ܸ� �� �����ٰ� ǥ���� ��, ���ʿ� exception specifier ��ü�� �� �� ���δٰ� ��
{
	cout << "Last" << endl;
	cout << "Throws exception" << endl;
	
	throw - 1;
	
	cout << "End last" << endl; // ���õ�
}

void third() throw(int) // int�� ���� ���ܸ� �����ٰ� ǥ���� ��
						// �ٸ�, ���������� throw(...)���� �۵��ؼ� ū �ǹ̴� ����, �� �� ����
{
	cout << "Third" << endl;

	last();

	cout << "End third" << endl; // stack unwinding�� ���� ���õ�
}

void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double) // catch�� �������� Ÿ���� �޶� stack unwinding�� ��
	{
		cerr << "Second caught double exception" << endl; // ���� ������ ���õ�
	}

	cout << "End second" << endl; // ��������
}

void first()
{
	cout << "First" << endl;

	try
	{
		second();
	}
	catch (int) // Ÿ���� ���Ƽ� throw�� ����
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