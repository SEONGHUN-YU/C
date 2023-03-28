#include <iostream> // cout, cin, endl, ...
#include <cstdio> // printf

int main()
{
	using namespace std;

	int x = 1024;
	double pi = 3.141592;

	cout << "Study C++\n"; // << std::endl;
	cout << "x is " << x << " pi is " << pi << endl;

	cout << "abc" << "\t" << "def" << endl;
	cout << "ab" << "\t" << "cdef" << endl;

	cout << "\a"; // 소리도 출력가능

	int k = 0;

	cout << "Before your input, k was " << k << endl;

	cin >> k;

	cout << "Your input is " << k << endl;

	return 0;
}