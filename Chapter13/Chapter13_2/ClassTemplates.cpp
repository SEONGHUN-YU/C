#include "MyArray.h"
//#include "MyArray.cpp" // �̷��� �ذ��ϴ� ��, ���߿� ������Ʈ�� Ŀ����, ������ �� ���� ������ �����
						// ����� �̷� ������ ������ ��

int main()
{
	MyArray<char> my_array(10); // class���� argument�� �� Ÿ���� �־���� template�� �� �� �ִ�

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 'a';

	my_array.print();

	return 0;
}