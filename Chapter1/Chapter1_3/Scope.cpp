#include <iostream>

using namespace std;

int main()
{
	int x(0); // x = 0; �� ������
	cout << x << " " << &x << endl;

	{
		// int x = 1; �ּҰ��� �޶���
		x = 1; // �ּҰ��� ������
		cout << x << " " << &x << endl;
	}

	cout << x << " " << &x << endl;

	return 0;
}