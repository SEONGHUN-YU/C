#include <iostream>
#include <typeinfo>
#include <iomanip> // setprecision()�� ���� ������

int main()
{
	using namespace std;

	// type casting�� ���ָ� (int)��, ����� ����ȯ�̴�
	// �Ͻ��� ����ȯ�� �׷��� ���� ��츦 ���ϰ�
	// ũ�� 2������ �ִ�
	// 1. numeric promotion
	float a = 1.0f;
	double d = a; // ���� ���� ū ������

	// 2. numeric conversion <- ������ �߻��� �� ����
	double dd = 3; // Ÿ���� �ٲ�ų� OR
	short s = 2; // ū ���� ���� ������

	int i = 30000;
	char c = i;
	cout << static_cast<int>(c) << endl;

	double ddd = 0.123456789;
	float f = ddd;
	cout << setprecision(12) << f << endl;

	int ii = 1234;
	float ff = ii;
	cout << setprecision(12) << ff << endl;

	float fff = 3.14;
	int iii = fff;
	cout << setprecision(12) << iii << endl;

	cout << 5u - 10u << endl; // �̻��ϰ� ����
	// ����ȯ���� �켱������ �ִµ�
	// int, unsigned int, long, unsigned long
	// long long, unsigned long long, float, double, long double
	// int�� �켱������ ���� ����, long double�� �켱������ ���� ����

	int k = int(4.0); // c++��Ÿ��
	int kk = (int)4.0; // c��Ÿ��
	int kkk = static_cast<int>(4.0); // �ֱٿ� ���� �� ���� ���?
	// �� �� ��ɻ� ���̴� ���ٴ� �� ?

	int n = 123;
	cout << typeid(n).name() << endl;
	cout << typeid(4.0).name() << endl;

	return 0;
}