#include <iostream>

void doSomething(const int& x)
{
	std::cout << x << std::endl;
}

int main()
{
	int x = 5;
	const int& ref_x = x;
	const int& ref_2 = ref_x;

	const int& ref = 3 + 4; // const ref에는 리터럴을 넣을 수 있다
							// 이 경우 주소도 생긴다
	std::cout << ref << " " << &ref << std::endl;

	// 그렇다면 const int랑 const int& 차이가 뭘까
	// 함수의 parameter로 넣을 때 리터럴을 넣을 수 있어서 좋다
	// 그냥 const int로 받게 되면 포인터로 받게 되는데
	// parameter에서 받을 때 const int&로 받게 되면
	// 주소를 복사하는 과정이 필요없어서 속도마저도 빠른 장점이 있음
	int a = 1;
	doSomething(123);
	doSomething(a);
	doSomething(a + 3);
	doSomething(3 * 4);

	return 0;
}