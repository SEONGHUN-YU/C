#include <iostream>

using namespace std;

void doSomething(const int& n) // �̷��� ������ �� �Լ� ������ ���� �ٲ� ��
{								// ���ÿ����ӿ��� �ұ��ϰ� ���� ���� �ٲ��
	// parameter�� �����ͷ� ���� ������ �ּҸ� �����ؾ��ϴµ�
	// ref(��������)�� ���� ������ �ּҸ� �����ϴ� �������� �ʿ���(���� ��ü�� ��) ȿ���� �� ���� �ӵ��� �� ������
	cout << &n << endl;
	// n = 10; parameter�� const�� �޾Ƽ� ���� �ٲ� �� ���� ��
	cout << "In doSomething" << n << endl;
}

void printElements(int(&arr)[5]) // array�� �Լ��� ���� ���� ref�� ����� �� ����
{								// �� ��� ����� �����ϰ� ������� ��
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

int main()
{
	int value = 5;
	int* ptr = nullptr; // ��¥ ��ȭ��ȣ�� �־��ִ� ����?
	ptr = &value; // �̷������ε� �����ϴٰ� ��

	int& ref = value; // ref�� �ݵ�� ����� ���ÿ� �ʱ�ȭ�� �Ǿ�� �Ѵ�
	// ref���� ���ͷ��� �� ����, ������ ���� �� ����
	// ref���� ���� ����� �ٲ���� �� �ֱ� ������ �����Ϸ��� ����� �� ��

	cout << ref << endl;
	ref = 10; // *ptr = 10; ó�� �۵��ϰ� �ִ�, ���Ҵ� ����
	cout << value << " " << ref << endl;
	cout << &value << " " << &ref << " " << ptr << " " << &ptr << endl;

	int x = 7;
	int& ref_x = x;

	const int y = 8;
	const int& ref_y = y; // ����� const�� �ٿ��ָ� ���� �� �־���

	int n = 20;
	cout << n << endl;
	cout << &n << endl;

	doSomething(n);
	cout << n << endl;

	const int length = 5;
	int arr[length] = { 1, 2, 3, 4, 5 };

	printElements(arr);

	Other ot;
	int &v1 = ot.st.v1; // �̷��� �����߾�� �ߴµ�, �� �� ref�� ����
	v1 = 1; // �������� �ſ� ª������ ������ �ִ�, �ӵ� ���ϵ� ����

	int val = 5;
	int* const ptr_v = &val;
	int& ref_v = val; // �� �� ���������� �����ʹ� ��ɻ� ������ �����ϴ�

	*ptr_v = 10;
	ref_v = 10; // ref�� ���������δ� �����ͷ� ������ �Ǿ�����

	return 0;
}