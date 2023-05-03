#include <iostream>
#include <typeinfo>

using namespace std;

/*int* doSomething(int* ptr_a)
{
	return nullptr;
}*/

struct Something
{
	int a, b, c, d; // 4 x 4 = 16 bytes
};

int main()
{
	int x = 5;
	double d = 123.0;

	cout << x << endl;
	cout << &x << endl; // & : address-of operator
	cout << (long long)&x << endl;

	// c++에는 pointer가 있고, reference가 따로 또 있다, 혼동에 주의
	// de-reference(역참조) operator *
	cout << *(&x) << endl;

	int *ptr_x = &x;
	double *ptr_d = &d;

	cout << sizeof(x) << endl;
	cout << sizeof(d) << endl;
	cout << sizeof(&x) << " " << sizeof(ptr_x) << endl;
	cout << sizeof(&d) << " " << sizeof(ptr_d) << endl;

	Something ss;
	Something* ptr_s;

	cout << sizeof(Something) << endl;
	cout << sizeof(ptr_s) << endl;

	cout << typeid(ptr_x).name() << endl;

	cout << ptr_x << endl;
	cout << *ptr_x << endl;

	cout << ptr_d << endl;
	cout << *ptr_d << endl;

	return 0;
}