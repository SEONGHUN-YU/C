#include <iostream>

using namespace std;

int main()
{
	// void my_void; ���̵�� �޸𸮸� �������� �ʱ� ������ ������ �� ����

	int i = 123;
	float f = 123.456f;

	void* my_void;

	my_void = (void*)&i; // ���߿� ���� �� ���̵� ������ ������
	my_void = (void*)&f; // ���� �ڼ��ϰ� �ٷ��� ����

	return 0;
}