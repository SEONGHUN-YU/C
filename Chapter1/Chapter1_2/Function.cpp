#include <iostream>

using namespace std;

int calcTwoNum(int a, int b)
{
	return a + b;
}

void print()
{
	cout << "hello" << endl;
}

void printHelloWorld() // parameter (void) ��������
{
	cout << "hello world" << endl;
	print();
	return; // ��������
}

int main()
{
	int sum = calcTwoNum(1, 2);

	printHelloWorld();

	return 0;
}