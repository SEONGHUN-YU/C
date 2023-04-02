#include <iostream>

using namespace std;

int main()
{
	// fundamental data types, built-in data types ��� �θ���, �⺻����

	// char, char16_t, char32_t, wchar_t #1
	// signed -> char, short, int, long, long long #2
	// unsigned -> char, short, int, long, long long #3
	
	// char�� CharacterŸ���̱⵵ �ϰ� IntegerŸ���̱⵵ �ϴ�
	// ������ �� ���������� ������ �����ϱ� ����
	// (signed) short (int)ó�� Ǯ�������� �ᵵ ���� ������ٰ� ��

	// float, double, long double #4
	// bool #5
	// void #6 ���߿� �����Ϳ��� ���̵� �����Ͷ�� �� ������ �߿��ϴٰ� ��
	// decltype(nullptr) #7 �� ������

	bool bVal = false;
	// char cVal = 'A'; // #A
	char cVal = 65;		// #B
	float fVal = 3.141592f; // float�� ������ �ڸ��� f�� ���δ�, �� ���̸� double�� ����ؼ� warning ��
	double dVal = 3.141592;

	auto aVal = 3.141592; // ��� C++�� �ִ� Ÿ��, �������� �� �ڷ����� ��������
	auto aVal2 = 3.141592f; // ���� �����

	// cout << (bVal ? 1 : 0) << endl;
	cout << bVal << endl; // 0�� ����
	// cout << (int)cVal << endl;	// #A�� �� 65�� ����
	cout << cVal << endl;			// #B�� �� 'A'�� ����
	cout << fVal << endl;
	cout << dVal << endl;
	cout << sizeof(aVal) << endl;
	cout << sizeof(aVal2) << endl;

	cout << sizeof(bool) << endl; // sizeof()���� Ÿ���� �־ �ǰ�
	cout << sizeof(bVal) << endl; // �ĺ��ڸ� �־ �ȴ�

	int a = (int)123.1; // copy initialization
	int b((int)123.1);	// direct initialization
	int c{ 123 }; // uniform initialization <- ���� �� �����ϴ�
	int k = 0, l(123), m{ 456 }; // k, l = 123, m; ó��, Ư������ �ʱ�ȭ ������ ���� �ִ�

	// �ֱٿ��� ����� ������, ����ϱ� ������ ����� ���ÿ� �ʱ�ȭ ��Ű�� ����� ��ȣ�Ѵ�

	return 0;
}