#include <iostream>

using namespace std;

int main()
{
	int value = 5;
	const int* ptr = &value; // �ּҸ� �����ͼ� �����ϰ�, ���� �д� �۾��� ������
	// *ptr = 6; value�� const�� �ٲ�鼭 ���� �� �ٲٰ� ��
	value = 6; // value�� const�� �ƴϰ�, pointer�� const�� ��� value�� ���� �ٲٴ� �� ���� ����
	
	cout << *ptr << endl;

	int value1 = 5;
	const int* ptr2 = &value1;
	int value2 = 6;
	ptr2 = &value2; // �̰� �� �ǳ�, �������� ���� �� �ٲٰڴٴ� ������, �ּ� ��ü�� �ٲ� �� ����

	int val = 5;
	int* const ptr3 = &val; // �� ���, �������� ���� �ٲٴ� �� �Ǵµ�, �ּҴ� �ٲ� �� ����
	*ptr3 = 15;
	cout << *ptr3 << endl;

	int val2 = 5;
	const int* const ptr4 = &val2; // �����Ͱ� ����� ��, (const ptr)�� ���� �ּҰ��� ����� ���ÿ� �ʱ�ȭ ������ ������ �� ��
	cout << *ptr4 << endl;

	int v = 5;
	const int* ptr_1 = &v; // �� ����(�ϳ��� �ּ�)�� �����Ͱ� ������ ���� ���� ���� <- ���� ����
	int* const ptr_2 = &v;
	const int* const ptr_3 = &v;

	return 0;
}