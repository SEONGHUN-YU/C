#include <iostream>

using namespace std;

int main()
{
	float pi = 3.14f;
	unsigned int n = 5u;
	long n2 = 5L;
	double d = 6.0e10;

	// Decimal : 0 1 2 3 4 5 6 7 8 9 10 11 ...
	// Octal : 0 1 2 3 4 5 6 7 10 11 12 13 ...
	// Hexa : 0 1 2 3 4 5 6 7 8 9 A B C D E F 10 ...

	// 0011 1010 1111 1111
	// 3A7F �̷� ������ ��û ª���� <- 16����

	int x = 012; // Octal 8����
	int y = 0xF; // Hexa 16����
	int z = 0b1010; // C++14���� ����, 2���� 1010
	int a = 0b1011'1111'1010; // ���� ���̿� �ִ� ' �� �����Ϸ��� ������, �������� ���� ��
	cout << x << endl;			// 2���� �ܿ� 10�������� ����� �� �ְ� �� �� �� �ִ� �� �ϴ�
	cout << y << endl;
	cout << z << endl;
	return 0;
}