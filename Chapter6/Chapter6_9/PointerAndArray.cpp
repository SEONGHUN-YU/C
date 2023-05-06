#include <iostream>

using namespace std;

//void printArray(int array[])
void printArray(int *array)
{
	cout << sizeof(array) << endl;
	cout << *array << endl;

	*array = 100;
}

struct MyStruct
{
	int array_t[5] = { 10, 20, 30, 40, 50 };
};

void doSomething(MyStruct ms)
{
	cout << sizeof(ms.array_t) << endl;
}

void doSomething_ptr(MyStruct *ms) // �迭�� struct�� class�ȿ� ������� ��쿡��
{									// pointer�� ������ȯ�� ���� ����
	cout << sizeof((*ms).array_t) << endl;
}

int main()
{
	// �����Ϳ� �����迭�� ��������� ����
	// �Լ��� parameter�� �����迭�� ������� ������
	// �Լ����� �޾Ƶ��̸鼭 �����ͷ� �ٲ������ ������, �����迭�ν� �� ���� ����
	MyStruct ms;
	cout << ms.array_t[0] << endl;
	cout << sizeof(ms.array_t) << endl;

	doSomething(ms);
	doSomething_ptr(&ms);

	int array[5] = { 9,7,5,3,1 };

	cout << array[0] << " " << array[1] << endl;
	cout << array << endl;
	cout << &array[0] << endl;
	
	cout << *array << endl;
	cout << sizeof(array) << endl; // 20

	int* ptr = array;
	cout << sizeof(ptr) << endl; // pointer

	// pointer arithmetic : ������ ����
	cout << *ptr << " " << *(ptr + 1) << endl; 

	char name[] = "oh yeah";
	cout << (char)(*name + 1) << endl;

	printArray(array);

	cout << array[0] << " " << *array << endl;

	return 0;
}

