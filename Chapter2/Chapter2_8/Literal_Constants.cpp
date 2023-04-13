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
	// 3A7F 이런 식으로 엄청 짧아짐 <- 16진수

	int x = 012; // Octal 8진수
	int y = 0xF; // Hexa 16진수
	int z = 0b1010; // C++14부터 생김, 2진수 1010
	int a = 0b1011'1111'1010; // 숫자 사이에 넣는 ' 는 컴파일러가 무시함, 가독성을 위한 것
	cout << x << endl;			// 2진수 외에 10진수에도 사용할 수 있고 다 쓸 수 있는 듯 하다
	cout << y << endl;
	cout << z << endl;
	return 0;
}