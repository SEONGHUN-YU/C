#include <iostream>
#include <vector>
#include <array>

class IntArray
{
private:
	int m_length = 0;
	int* m_data = nullptr;

public:
	// 시간 남을 때, 직접 구현해볼 것
	
	// Constructors
	// Destructors
	// initialize()
	// reset();
	// resize();
	// insertBefore(const int& value, const int& index);
	// remove(const int& index);
	// push_back(const int& value);
};

int main()
{
	//IntArray my_arr{ 1, 3, 5, 7, 9 };
	//my_arr.insertBefore(10, 1); -> 1, 10, 3, 5, 7, 9
	//my_arr.remove(3); -> 1, 10, 3, 7, 9
	//my_arr.push_back(13); -> 1, 10, 3, 7, 9, 13

	std::vector<int> int_vec;
	std::array<int, 10> int_arr;

	return 0;
}