#include <iostream>

void doSomething(const int& x)
{
	std::cout << x << std::endl;
}

int main()
{
	int x = 5;
	const int& ref_x = x;
	const int& ref_2 = ref_x;

	const int& ref = 3 + 4; // const ref���� ���ͷ��� ���� �� �ִ�
							// �� ��� �ּҵ� �����
	std::cout << ref << " " << &ref << std::endl;

	// �׷��ٸ� const int�� const int& ���̰� ����
	// �Լ��� parameter�� ���� �� ���ͷ��� ���� �� �־ ����
	// �׳� const int�� �ް� �Ǹ� �����ͷ� �ް� �Ǵµ�
	// parameter���� ���� �� const int&�� �ް� �Ǹ�
	// �ּҸ� �����ϴ� ������ �ʿ��� �ӵ������� ���� ������ ����
	int a = 1;
	doSomething(123);
	doSomething(a);
	doSomething(a + 3);
	doSomething(3 * 4);

	return 0;
}