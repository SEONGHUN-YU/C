#include <iostream>

using namespace std;

// void pointer, generic(��������) pointer

enum Type
{
	INT,
	FLOAT,
	CHAR
};

int main()
{
	int i = 5;
	float f = 3.0f;
	char c = 'a';

	void* ptr = nullptr;

	ptr = &i;
	ptr = &f;
	//ptr = &c;

	Type type = FLOAT;
	if (type == FLOAT) cout << *static_cast<float*>(ptr) << endl;
	else if (type == INT) cout << *static_cast<int*>(ptr) << endl;
	else cout << *static_cast<char*>(ptr) << endl;

	cout << &f << " " << ptr << endl; // �ּ� ��ü�� �� �� ����
	// cout << ptr + 1 << endl; ����, void pointer�� ������ �� ��
	// �ڷ����� ��õǾ� ���� �ʾƼ�, �� bytes�� ���ؾ� �ϴ��� �� ���� ���� ������ ���Ƶ�
	// cout << *ptr << endl; ���������� �׳� �ؼ��� �������� �� ��
	cout << *static_cast<float*>(ptr) << endl;

	int* ptr_i = &i;
	cout << ptr_i << endl;
	cout << ptr_i + 1 << endl;

	return 0;
}