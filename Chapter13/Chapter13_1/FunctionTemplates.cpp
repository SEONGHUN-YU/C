#include <iostream>
#include "Cents.h"

template<typename T>
//template<class T> �̷� �͵� �ִ�, ���� class�� ���� �ڸ���� �� ����ϴ� ����(���ӽ�)
//typename�̶�� �� �Ŷ� class��� �� �Ŷ� ���� ����ϴٰ� ���� ��

T getMax(T x, T y) // T�ڸ��� ���� �������� �����Ϸ��� ã�Ƴ��� ���������� �˾Ƽ� ó�����ش�
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