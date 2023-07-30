#include <iostream>
#include "Cents.h"

template<typename T>
//template<class T> 이런 것도 있다, 뭔가 class가 들어올 자리라는 걸 명시하는 느낌(뉘앙스)
//typename이라고 쓴 거랑 class라고 쓴 거랑 거의 비슷하다고 보면 됨

T getMax(T x, T y) // T자리에 뭐가 들어가야할지 컴파일러가 찾아내고 내부적으로 알아서 처리해준다
{
	return x > y ? x : y;
}

int main()
{
	std::cout << getMax(1, 2) << std::endl;
	std::cout << getMax(3.14, 1.592) << std::endl;
	std::cout << getMax(1.0f, 3.4f) << std::endl;
	std::cout << getMax('a', 'c') << std::endl;

	std::cout << getMax(Cents(5), Cents(9)) << std::endl;

	return 0;
}