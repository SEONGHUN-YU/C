#include <iostream>

using namespace std;

const char* getName()
{
	return "Jack Jack";
}

int main()
{
	//char name[] = "haha hoho";
	//char* name = "Jack Jack"; // ������ ���� ��� �޸𸮸� ��� ���� ���ΰ�, �� ���� �ƹ��� ������ ���
								// �����Ϳ��� ���ͷ��� ���� �� ����, �����ʹ� ����, �޸��� �ּҸ� ����Ű�⸸ �� �� �ִ�
	const char* name = "Jack Jack"; // const�� �ٿ��� ��ȣ���� ���ó�� ����� ���� �� �ְ� �ȴ�
	const char* name2 = getName();
	cout << (uintptr_t)name << endl;
	cout << (uintptr_t)name2 << endl;

	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello, World!";
	
	cout << int_arr << endl;
	cout << char_arr << endl;
	cout << name << endl;
	// cout���� ���ڿ��� �����Ͱ� ������ Ư���� ó�����ش�

	char c = 'Q';
	cout << *&c << endl;
	// �׷��� ���輺�� �ִ�, �ּҷ� ������ �� �ٽ� �������ؼ� ������ �ٲ��� ���

	return 0;
}