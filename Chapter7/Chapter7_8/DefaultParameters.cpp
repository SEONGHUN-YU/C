#include <iostream>
#include <string>

using namespace std;

void print(int x)
{
	cout << x << endl;
}

//void print(int x, int y = 20) <- arguments�� 1���� ���� �� ���� �Ͱ� ������ �� �ǰ� ��
// ambiguous(��ȣ��)�� ���ܹ����� �������� �� ��, �ٽ� ���ؼ�, default ������ overloading���� ������ �ش�
void print(int x, int y) // <- �̷� ������ �ϸ� ����
{
	cout << x << endl;
}

void test(int x = 10, int y = 20, int z = 30); // in header
// �⺻�� ������ �������, �ҽ������� ��Ʋ� �� �������� ����� �Ѵ�
// �ٸ�, ��������ʿ� default�� ���ǵǾ� �ִ� ���� ����, �Ϲ������� �׷��� �Ѵٰ� �Ѵ�

//void test(int x, int y = 20, int z) <- Error
void test(int x, int y, int z) // ���� �����ʿ� �ִ� ��Ҹ� ��������
{	// �����ʿ������� �������� default ���� ä������ �� �ִµ�
	// ���ʸ� default�� �شٴ��� �߰����� default�� �شٴ��� �ϴ� ���� �Ұ����ϴ�
	
	cout << x << " " << y << " " << z << endl;
}

/*void print(std::string str) { cout << str << endl; }
void print(char ch = ' ') { cout << ch << endl; }*/ // ������ ��?

int main()
{
	print(1);
	test(1);

	return 0;
}