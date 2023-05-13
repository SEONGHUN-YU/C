#include <iostream>

struct Person
{
	int age;
	double weight;
};

int main()
{
	Person person;
	person.age = 5;
	person.weight = 30;

	Person& ref = person;
	ref.age = 15; // 주로 쓰는 방법

	Person* ptr = &person;
	ptr->age = 30;
	//(*ptr).age = 20; // 문법이 2개임, 근데 이 방법은 잘 안 씀, 보통은 ref를 씀
	// *보다 .이, 연산 우선순위가 높아서 ()를 쳐주어야 함

	Person& ref2 = *ptr;
	ref2.age = 45;

	std::cout << &person << std::endl;
	std::cout << &ref2 << std::endl;

	return 0;
}