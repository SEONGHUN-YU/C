#include <iostream>
#include "MyConstants.h"

using namespace std;

int value = 123;

//void doSomething()
//{
//	// static int a = 1;
//	++a;
//	cout << a << endl;
//}

// forward declaration : ���� ����
extern void doSomething(); // ������ extern�̶�� Ű���尡 �ʿ��ѵ�, ������ �� �ִ� ��
extern int a;

/*
	int g_x; // external linkage <- �ʱ�ȭ�� �� �� ���� ����
	static int g_x; // internal linkage <- �ʱ�ȭ�� ���� ����, �ٸ� cpp���Ͽ��� ������ �� ���� ���� ����

	int g_y(1); �ʱ�ȭ�� �� ���� ����
	static int g_y(1); �ʱ�ȭ�� �� ���� ����
	const int g_y(1); ���� ���� �ȿ����� ������ �� �ִ� ���

	forward declaration�� ���
	extern int g_z; <- �ٸ� �������� �ʱ�ȭ�� �Ǿ��־�� ��
	extern const int g_z; <- ����������, �ٸ� �������� �ʱ�ȭ�� �Ǿ��־�� ��

	extern int g_w(1); <- �ٸ� �������� �ʱ�ȭ�ϸ� �� ��
	extern const int g_w(1); <- �ʱ�ȭ�� ��, �ٸ� cpp����(�ܺ�)������ ������ �� �ִ� ���
*/

int main()

{
	cout << "In main.cpp file " << Constants::pi << " " << &Constants::pi << endl;
 	doSomething();

	cout << a << endl;

	cout << value << endl;
	int value = 1;
	cout << ::value << endl; // global scope operator�� ����� ���
	cout << value << endl;

	return 0;
}