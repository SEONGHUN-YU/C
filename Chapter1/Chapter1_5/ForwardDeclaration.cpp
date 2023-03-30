#include <iostream>

using namespace std;

int add(int a, int b); // forward declaration(전방 선언)
int multiply(int a, int b); // 이 부분을 프로토타입 이라고 부른다

int main()
{
	cout << add(1, 2) << endl;
	cout << multiply(1, 2) << endl;

	return 0;
}

// definition(정의부)
int add(int a, int b)
{
	return a + b; // indenting(들여쓰기)
}

int multiply(int a, int b)
{
	return a * b;
}

