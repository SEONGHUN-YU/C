#include <iostream>
#include <string>

using namespace std;

int main()
{
	string my_str("01234567");
	my_str.reserve(1000); // capacity�� reserve�� �ִ��� ������ �÷���(�Ϲ������� �ణ ��)

	cout << my_str.length() << endl;
	cout << my_str.size() << endl;
	cout << my_str.capacity() << endl; // �̰Ŵ� �����Ϸ��� OS�� ���� �ٸ� �� ����
	// �� �� ������ memory re-allocation�� ���ϱ� ���� capacity�� �����Ӱ� �÷���
	cout << my_str.max_size() << endl;
	
	cout << boolalpha;
	cout << my_str.empty() << endl; // ""�� ����ִٰ� ����, null character�� �������� ����

	return 0;
}