#include <iostream>
#include <cmath> // pow(제곱) 함수를 위해 가져옴
#include <limits>

using namespace std;

int main()
{
	short s = 1; // 2 byte = 2 * 8 bits = 16 bits
	int i = 1;
	long l = 1;
	long long ll = 1;

	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;

	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl;
	cout << std::numeric_limits<short>::max() << endl;
	cout << std::numeric_limits<short>::min() << endl;
	cout << std::numeric_limits<short>::lowest() << endl;

	s = 32767;
	s += 1;
	cout << s << endl; // overflow

	s = -32768;
	s -= 1;
	cout << s << endl; // overflow

	unsigned int k = -1;
	cout << k << endl;
	cout << (float)22 / 4 << endl; // int일 때는 나머지는 버린다

	return 0;
}