#include <iostream>

using namespace std;

int add(int a, int b); // forward declaration(���� ����)
int multiply(int a, int b); // �� �κ��� ������Ÿ�� �̶�� �θ���

int main()
{
	cout << add(1, 2) << endl;
	cout << multiply(1, 2) << endl;

	return 0;
}

// definition(���Ǻ�)
int add(int a, int b)
{
	return a + b; // indenting(�鿩����)
}

int multiply(int a, int b)
{
	return a * b;
}

