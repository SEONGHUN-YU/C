#include <iostream>
#include <bitset> // 2������ �ٲ㼭 ������ִ� lib

using namespace std;

int main()
{
	// <<
	// >>
	// ~, &, |, ^

	unsigned int a = 3;

	cout << std::bitset<4>(a) << endl;

	unsigned int b = a << 2;

	cout << std::bitset<4>(b) << " " << b << endl;

	unsigned int c = 1024;
	cout << std::bitset<16>(c) << endl;
	cout << std::bitset<16>(~c) << " " << (~c) << endl;

	unsigned int m = 0b1100;
	unsigned int n = 0b0110;

	cout << m << " " << n << endl; // 2������ ������, 10������ ��µ�
	cout << std::bitset<4>(m & n) << endl;
	cout << std::bitset<4>(m | n) << endl;
	cout << std::bitset<4>(m ^ n) << endl;

	return 0;
} 