#include <iostream>
#include <vector> // ���� �迭�� ��ü�� �� ����

int main()
{
	//std::array<int, 5> array; // �����̾ ����� ��õǾ� �־�� ����
	std::vector<int> array;

	std::vector<int> array2 = { 1,2,3,4,5 };
	std::cout << array2.size() << std::endl;

	std::vector<int> array3 = { 1,2,3 };
	std::cout << array3.size() << std::endl;

	std::vector<int> array4{ 1,2,3 }; // uniform initialization�� ����
	std::cout << array4.size() << std::endl;

	std::vector<int> arr = { 1,2,3,4,5 };

	arr.resize(10); // ����� ����� �ٲ� �� �ִ�, �Ҵ� �� �� �͵��� 0���� ä����

	for (const auto& v : arr)
		std::cout << v << " ";
	std::cout << std::endl;

	std::cout << arr[1] << std::endl;
	std::cout << arr.at(1) << std::endl;

	// vector�� ������ ��Ϲ����� �����ų�, return���� �Լ��� ����ǰų� �� ��, �޸𸮸� �˾Ƽ� �����ش�
	int* my_arr = new int[5];
	delete[] my_arr; // �� ������ �ʿ䰡 ����

	return 0;
}