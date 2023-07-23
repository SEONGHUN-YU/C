#include <iostream>

using namespace std;

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
	cin >> op;

	// static binding (early binding) // 빌드타임에 변수, 함수들이 깔끔하게 다 정해져 있음, 빠름
	/*int result = 0;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subtract(x, y); break;
	case 2: result = multiply(x, y); break;
	}

	cout << result << endl;*/

	// Dynamic binding (late binding) // 한 번에 실행하는 게 아니라서, 주소를 타고 가야해서 느림, 대신에 유연한 코딩이 가능해짐
	int(*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = subtract; break;
	case 2: func_ptr = multiply; break;
	}

	cout << func_ptr(x, y) << endl;

	return 0;
}