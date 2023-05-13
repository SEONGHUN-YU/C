#include <iostream>
#include <limits> // numeric_limits<타입>:: 을 사용하기 위함
#include <algorithm> // max()를 사용하기 위함
#include <vector>

int main()
{
	// c++11부터 지원함
	// int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	std::vector<int> fibonacci = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	// change array values
	for (auto& n : fibonacci) // int일 때는 로컬영역이라 값이 안 바뀌는데, int&일 때는 값을 바꿔줄 수 있다
		n *= 10;

	// output
	for (const auto n : fibonacci) // 읽기만 하고 싶을 때는 const를 써주는 게 일반적이다
		std::cout << n << " ";
	std::cout << std::endl;

	// 가장 큰 값 찾는 로직
	int max_number = std::numeric_limits<int>::lowest();
	for (const auto& n : fibonacci)
		max_number = std::max(max_number, n);
	std::cout << max_number << std::endl;

	// array를 동적 할당하게 되면 for-each를 사용할 수가 없음
	// => for-each의 단점 <- 그러나 vector를 쓰면 해결됨
	// vector는 동적 할당 배열을 아주 편하게 사용할 수 있게 만든 느낌이다

	return 0;
}