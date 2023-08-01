#include "MyArray.h"

int main()
{
	// std::vector<double> my_array; my_array.resize(100);
	// MyArray<double> my_array(100);
	// 위의 2가지 경우는 메모리가 동적할당된 것, 런타임에 결정되었다
	// template로 사이즈를 정할 때에는 컴파일에 결정되어야 한다
	MyArray<double, 100> my_array; // std::array<double, 100>

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;

	my_array.print();

	return 0;
}