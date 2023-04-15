#include <iostream>

// template ?

auto add(int x, int y) // auto는 parameter에는 쓸 수 없다
{
	return x + y; // c++17부터 여러개의 return값을 동시에 반환할 수 있는 방법이 존재하는 듯?
}

auto add(double x, double y) -> double // 트레일링, 자취를 남기는 거 ?
{										// Python의 type hint랑 비슷한 거 같다
	return x + y;
}

int main()
{
	using namespace std;

	auto a = 123;
	auto d = 123.0;
	auto c = 1 + 2.0; // 실수
	auto result = add(1, 2);

	return 0;
}