#include <iostream>
#include <limits> // numeric_limits<Ÿ��>:: �� ����ϱ� ����
#include <algorithm> // max()�� ����ϱ� ����
#include <vector>

int main()
{
	// c++11���� ������
	// int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	std::vector<int> fibonacci = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	// change array values
	for (auto& n : fibonacci) // int�� ���� ���ÿ����̶� ���� �� �ٲ�µ�, int&�� ���� ���� �ٲ��� �� �ִ�
		n *= 10;

	// output
	for (const auto n : fibonacci) // �б⸸ �ϰ� ���� ���� const�� ���ִ� �� �Ϲ����̴�
		std::cout << n << " ";
	std::cout << std::endl;

	// ���� ū �� ã�� ����
	int max_number = std::numeric_limits<int>::lowest();
	for (const auto& n : fibonacci)
		max_number = std::max(max_number, n);
	std::cout << max_number << std::endl;

	// array�� ���� �Ҵ��ϰ� �Ǹ� for-each�� ����� ���� ����
	// => for-each�� ���� <- �׷��� vector�� ���� �ذ��
	// vector�� ���� �Ҵ� �迭�� ���� ���ϰ� ����� �� �ְ� ���� �����̴�

	return 0;
}