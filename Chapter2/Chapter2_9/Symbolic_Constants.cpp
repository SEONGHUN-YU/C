#include <iostream>
#include "MY_CONSTANTS.h"

#define PRICE_PER_ITEM 30 // 매크로명은, 모두 대문자로 쓰는 관습이 있음


using namespace std;

void printNumber(const int my_number)
{
	cout << my_number << endl;
}

int main()
{
	printNumber(123);
	const double gravity{ 9.8 };
	// double const 일반적인 경우에는 순서 바꾸는 건 크게 상관은 없다
	// 다만 나중에 포인터에서는 의미가 다르다고 한다

	int number;
	cin >> number;
	constexpr int my_const(123); // 컴파일타임 상수
	const int special_number(number); // 런타임 상수

	int num_item = 123;
	int price = num_item * PRICE_PER_ITEM; // 매크로를 상수처럼 사용해서 짠 코드
											// 매우 옛날방식 코딩이며, 이런 식으로 쓰지말자는 참고 차원에서 남김
											// 이유 1. 디버깅이 번거로워짐
											// 이유 2. 너무 전역범위여서 좋지 않음
	const int price_per_item = 30;
	price = num_item * price_per_item; // 개선한 모습

	double radius;
	cin >> radius;
	double circumference = 2.0 * radius * constants::pi;

	return 0;
}