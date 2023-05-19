#include <iostream>

void doSomething(int y)
{
	std::cout << "In func " << y << " " << &y << std::endl;
}

int main()
{
	doSomething(5);

	int x = 6;

	std::cout << "In main " << x << " " << &x << std::endl;

	doSomething(x);
	doSomething(x + 1);

	return 0;
}