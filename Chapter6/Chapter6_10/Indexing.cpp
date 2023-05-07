#include <iostream>

using namespace std;

int main()
{
	int array[] = { 9,7,5,3,1 };
	int* ptr = array;
	for (int i = 0; i < 5; i++)
	{
		//cout << array[i] << " " << (uintptr_t) & array[i] << endl;
		cout << *(ptr + i) << " " << (uintptr_t)(ptr + i) << endl; // 위와 같다
	}

	char name[] = "haha hoho";
	const int n_name = sizeof(name) / sizeof(char);
	char* ptr_n = name;

	for (int i = 0; i < n_name; i++)
	{
		cout << *(ptr_n + i);
	}
	cout << endl;

	double value = 7.0;
	double* ptr_d = &value;

	cout << uintptr_t(ptr_d - 1) << endl;
	cout << uintptr_t(ptr_d) << endl;
	cout << uintptr_t(ptr_d + 1) << endl;
	cout << uintptr_t(ptr_d + 2) << endl;

	return 0;
}