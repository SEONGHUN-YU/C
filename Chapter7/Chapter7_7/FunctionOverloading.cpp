#include <iostream>
#include <string>

using namespace std;

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

// return Ÿ���� �ٸ� �͸� ������� overloading �Ұ���
// parameter�� �޶�� ��, return Ÿ���� ���Ƶ� ��� ����
// typedef�� ������ �� ��, �����Ϸ����� �������� �� ����

// parameter�� ���� ��, �浹�� ȸ���ϴ� ���
// 1. �Լ� �̸��� �ٲ۴�
// 2. void �Լ��� parameter�� ref�� �޾Ƽ� ���� return�� �����Ѵ�

// ��ġ�� ��Ȯ�� �� �� ���� ���� <- �߿��� ���� ��
//void print(char* x) {} // 'a'�� int�� �ν��ع���
//void print(int x) {}

void print(unsigned int value) {}
void print(float value) {}

int main()
{
	add(1, 2); // �����ε��� �Լ� �߿���, ��� �Լ��� ȣ���� ����
	add(3.0, 4.0); // �����ϵǱ� ���� Ȯ���� �����Ǿ� �־�� �Ѵ� -> �̰� �����ؾ߸� �������� ��

	print(unsigned int('a')); // �̷� ������ ��Ȯ�� �ϸ�, ��ȣ���� �ؼҰ� �ȴ�
	print(0u);
	print(3.14159f);

	return 0;
}