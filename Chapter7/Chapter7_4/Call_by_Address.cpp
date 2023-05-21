#include <iostream>

using namespace std;

typedef int* pint;

void foo(pint ptr) // ���ο� �����͸� �����ϰ� &value�� �����ؼ�
{					// �ʱ�ȭ ��Ű�� ������ �� <- ������������
	cout << *ptr << " " << ptr << " " << &ptr << endl;
	*ptr = 10; // �����͸� ����Ͽ� �Լ��� return(���)�� ��ó�� ����ϱ⵵ �Ѵ�
}

void ptr_like_ref(double degrees, double* sin_out, double* cos_out) // �����͸� ����ϴ� ��, �ణ C-Style�̶�� �Ѵ�
{	// �����͸� �̿��Ͽ� ref�� ����� �Ͱ�, �����ϰ� �۵���ų �� �ִ�
	*sin_out = 1; // <- �޸� �ּҸ� ã�ư��� �� ���� �ٲ��ִ� ��
	*cos_out = 2; // ���� �ٲ��� �� �ִٰ� �ؼ�, ptr�� ref�� �����ؼ��� �� �ȴ�
	// �����Ͷ�� ����, ���������δ� call by value�� ����Ѵٴ� ���� ������ �� �ȴ�
}

void printArray(const int* const ptr, int* arr, int length)
{ // parameter�� �����Ͱ� ���� �� const int������ ���� ������
	// const int const ptr������ �� �Ѵ�, ptr�� �ٲ�ٰ� �ؼ�
	// �ٱ��� �ٸ� ������ ������ �ٲ�� �� �ƴϱ� ������, const�� ���� �� ���̴� ��
	// �ٸ�, �����ϰų� �� �� �Ǽ��� ���̱� ���� ���̴� ���� ����
	for (int i = 0; i < length; ++i)
		cout << arr[i] << endl;
	arr[0] = 10; // []�� ����� *&(������)�� �Ȱ��� �ſ��� !!!
}

// parameter�� �����͸� ��û ���� ����ִ� �迭�� ���� ��
// �ּ� �ϳ��� �����ϴ� ������, �� ������ �����͸� ��� �����ϴ� �ͺ��� �ξ� ȿ���� ����
// �׷� �������� �����͸� ����߾��µ�, �ֱٿ��� ���� ref�� ��ü�ǰ� �ִ�
// C�� C++�� ����

int main()
{
	int value = 5;
	cout << value << " " << &value << endl;
	int* ptr = &value;
	cout << &ptr << endl;
	foo(ptr);
	cout << value << endl;
	foo(&value);
	//foo(5); ���ͷ��� �� �ȴ�

	double degrees(30);
	double sin, cos;					// parameter�� �����͸� ���� ����
	ptr_like_ref(degrees, &sin, &cos); // &�� �ٿ��� �־��ְų�, ptr�� �־���� ��
	cout << sin << " " << cos << endl;
	// �ǿ����� �鿡���� ptr���� ref�� ���� �� �� ���ϴٰ� ��

	return 0;
}