#include <iostream>
#include <cassert> // assert.h ?
#include <array>

void printValue(const std::array<int, 5>& my_array, const int& ix)
{
	assert(ix >= 0);
	assert(ix <= my_array.size() - 1); // &&로 assert()안에 묶어줄 수 있지만
	// 이런 식으로 쪼개놓는 것이, 정확히 어디서 문제를 일으키는 건지 알기 더 쉽다고 함
	std::cout << my_array[ix] << std::endl;
}

int main()
{
	int number = 5;
	assert(number == 5); // debug 모드에서 프로그래머가 소프트웨어를 테스트할 때만 작동함

	std::array<int, 5> my_array{ 1,2,3,4,5 };
	printValue(my_array, 3);

	const int x = 5;
	assert(x == 5);	// assert는 런타임에 체크를 해준다
	static_assert(x == 5, "x should be 5"); // static_assert는 컴파일타임에 체크를 해준다
	// static_assert는 컴파일타임에 결정이 되는 경우에만 사용할 수 있다 ex) 상수

	return 0;
}