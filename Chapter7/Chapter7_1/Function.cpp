#include <iostream>

using namespace std;

int foo(int x, int y);

int foo(int x, int y) // �������� ���� ����Ǿ� �����ȴ�
{
	return x + y;
} // parameter���� ����� �������� �Լ��� ����ʰ� ���ÿ�
// �޸𸮸� OS�� �ݳ��ϸ� ������� �ȴ� <- parameter���� ���ú������ �Ҹ�

int main()
{
	int x = 1, y = 2;
	foo(6, 7); // arguments (actual parameters : �� ����?)
	foo(x, y + 1);
	// ���� ���� ����, ������ ���� ����, �ּҿ� ���� ������ �ִ�
	// call by value, call by reference
	return 0;
}