#include <iostream>
#include <vector> // 동적 배열을 대체할 수 있음

int main()
{
	//std::array<int, 5> array; // 정적이어서 사이즈가 명시되어 있어야 했음
	std::vector<int> array;

	std::vector<int> array2 = { 1,2,3,4,5 };
	std::cout << array2.size() << std::endl;

	std::vector<int> array3 = { 1,2,3 };
	std::cout << array3.size() << std::endl;

	std::vector<int> array4{ 1,2,3 }; // uniform initialization이 가능
	std::cout << array4.size() << std::endl;

	std::vector<int> arr = { 1,2,3,4,5 };

	arr.resize(10); // 사이즈도 맘대로 바꿀 수 있다, 할당 안 된 것들은 0으로 채워짐

	for (const auto& v : arr)
		std::cout << v << " ";
	std::cout << std::endl;

	std::cout << arr[1] << std::endl;
	std::cout << arr.at(1) << std::endl;

	// vector의 장점은 블록밖으로 나가거나, return으로 함수가 종료되거나 할 때, 메모리를 알아서 지워준다
	int* my_arr = new int[5];
	delete[] my_arr; // 이 과정이 필요가 없음

	return 0;
}