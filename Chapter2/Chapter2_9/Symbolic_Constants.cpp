#include <iostream>
#include "MY_CONSTANTS.h"

#define PRICE_PER_ITEM 30 // ��ũ�θ���, ��� �빮�ڷ� ���� ������ ����


using namespace std;

void printNumber(const int my_number)
{
	cout << my_number << endl;
}

int main()
{
	printNumber(123);
	const double gravity{ 9.8 };
	// double const �Ϲ����� ��쿡�� ���� �ٲٴ� �� ũ�� ����� ����
	// �ٸ� ���߿� �����Ϳ����� �ǹ̰� �ٸ��ٰ� �Ѵ�

	int number;
	cin >> number;
	constexpr int my_const(123); // ������Ÿ�� ���
	const int special_number(number); // ��Ÿ�� ���

	int num_item = 123;
	int price = num_item * PRICE_PER_ITEM; // ��ũ�θ� ���ó�� ����ؼ� § �ڵ�
											// �ſ� ������� �ڵ��̸�, �̷� ������ �������ڴ� ���� �������� ����
											// ���� 1. ������� ���ŷο���
											// ���� 2. �ʹ� ������������ ���� ����
	const int price_per_item = 30;
	price = num_item * price_per_item; // ������ ���

	double radius;
	cin >> radius;
	double circumference = 2.0 * radius * constants::pi;

	return 0;
}