#include <iostream>
#include <array> // ���� �迭�� ��ü�� �� ����
#include <algorithm> // sort �Ϸ��� ������

void printLength(const std::array<int, 5>& my_arr)
{
	std::cout << my_arr.size() << std::endl;
}

int main()
{
	//int array[5] = { 1,2,3,4,5 };
	std::array<int, 5> my_arr = { 1,21,3,40,5 };
	//my_arr = { 0,1,2,3,4 }; // ó���� ������ ������� Ŀ�� ���� ������
	//my_arr = { 0,1,2 }; // �� �۰� �Ҵ����� ���� �ִ�, �������� 0���� ä����

	std::cout << my_arr[0] << std::endl; // ������ �����Ϸ��� ��, �����Ⱚ ���� �� ����
	std::cout << my_arr.at(0) << std::endl; // ������ �� ������ ����ó���� ��, �ӵ��� ���� �� ����
	std::cout << my_arr.size() << std::endl;
	printLength(my_arr);

	for (auto& n : my_arr) std::cout << n << " ";
	std::cout << std::endl;

	//std::sort(my_arr.begin(), my_arr.end()); // �Ϲ� ����
	std::sort(my_arr.rbegin(), my_arr.rend()); // ���� ����
	for (auto& n : my_arr) std::cout << n << " "; // ���� �� ���
	std::cout << std::endl;

	return 0;
}