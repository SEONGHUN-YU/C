#include <iostream>
#include <array> // 정적 배열을 대체할 수 있음
#include <algorithm> // sort 하려고 가져옴

void printLength(const std::array<int, 5>& my_arr)
{
	std::cout << my_arr.size() << std::endl;
}

int main()
{
	//int array[5] = { 1,2,3,4,5 };
	std::array<int, 5> my_arr = { 1,21,3,40,5 };
	//my_arr = { 0,1,2,3,4 }; // 처음에 선언한 사이즈보다 커질 수는 없지만
	//my_arr = { 0,1,2 }; // 더 작게 할당해줄 수는 있다, 나머지는 0으로 채워짐

	std::cout << my_arr[0] << std::endl; // 무조건 접근하려고 함, 쓰레기값 나올 수 있음
	std::cout << my_arr.at(0) << std::endl; // 접근할 수 없으면 예외처리를 함, 속도가 조금 더 느림
	std::cout << my_arr.size() << std::endl;
	printLength(my_arr);

	for (auto& n : my_arr) std::cout << n << " ";
	std::cout << std::endl;

	//std::sort(my_arr.begin(), my_arr.end()); // 일반 정렬
	std::sort(my_arr.rbegin(), my_arr.rend()); // 역순 정렬
	for (auto& n : my_arr) std::cout << n << " "; // 정렬 후 출력
	std::cout << std::endl;

	return 0;
}