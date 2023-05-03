#include <iostream>
#include <cstddef>

void doSomething(double* ptr)
{
	std::cout << "address of pointer variable in doSomething() " << &ptr << std::endl;

	if (ptr != nullptr)
	{
		// do something useful
		std::cout << *ptr << std::endl;
	}
	else
	{
		// do nothing with ptr
		std::cout << "Null ptr, do nothing" << std::endl;
	}
}

int main()
{
	double* ptr_test = 0; // c-style 0 또는 NULL을 넣어줬었음
	double* ptr_test2 = NULL;
	double* ptr{ nullptr }; // modern c++ style

	doSomething(ptr);
	doSomething(nullptr);

	double d(123.4);
	doSomething(&d);

	ptr = &d;
	doSomething(ptr);

	std::nullptr_t nptr;

	std::cout << "address of pointer variable in main() " << &ptr << std::endl;

	return 0;
}