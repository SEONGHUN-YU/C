#include <iostream>
#include <cassert> // assert.h ?
#include <array>

void printValue(const std::array<int, 5>& my_array, const int& ix)
{
	assert(ix >= 0);
	assert(ix <= my_array.size() - 1); // &&�� assert()�ȿ� ������ �� ������
	// �̷� ������ �ɰ����� ����, ��Ȯ�� ��� ������ ����Ű�� ���� �˱� �� ���ٰ� ��
	std::cout << my_array[ix] << std::endl;
}

int main()
{
	int number = 5;
	assert(number == 5); // debug ��忡�� ���α׷��Ӱ� ����Ʈ��� �׽�Ʈ�� ���� �۵���

	std::array<int, 5> my_array{ 1,2,3,4,5 };
	printValue(my_array, 3);

	const int x = 5;
	assert(x == 5);	// assert�� ��Ÿ�ӿ� üũ�� ���ش�
	static_assert(x == 5, "x should be 5"); // static_assert�� ������Ÿ�ӿ� üũ�� ���ش�
	// static_assert�� ������Ÿ�ӿ� ������ �Ǵ� ��쿡�� ����� �� �ִ� ex) ���

	return 0;
}