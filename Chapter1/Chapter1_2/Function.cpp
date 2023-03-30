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

void printHelloWorld() // parameter (void) 생략가능
{
	cout << "hello world" << endl;
	print();
	return; // 생략가능
}

int main()
{
	int sum = calcTwoNum(1, 2);

	printHelloWorld();

	return 0;
}