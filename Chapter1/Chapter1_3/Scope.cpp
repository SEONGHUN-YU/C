#include <iostream>

using namespace std;

int main()
{
	int x(0); // x = 0; 과 동일함
	cout << x << " " << &x << endl;

	{
		// int x = 1; 주소값이 달라짐
		x = 1; // 주소값이 유지됨
		cout << x << " " << &x << endl;
	}

	cout << x << " " << &x << endl;

	return 0;
}