#include <iostream>
#include <limits>

using namespace std;

int main()
{
	char c1(65);
	char c2('A');

	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;
	
	// c-style casting
	cout << (char)65 << endl;
	cout << (int)'A' << endl;

	// cpp style casting
	cout << char(65) << endl;
	cout << int('A') << endl;

	// ���� 2�� ����� ������ȯ��Ű�� ������ ���ϰ�
	// �Ʒ� ����� �����Ϸ�����, ���� �� ĳ������ ������ ������ ����� ������ ���ϴ�

	cout << static_cast<char>(65) << endl; // �������� ĳ�������� ���� ������ ���� ���̴� ���ϴ�
	cout << static_cast<int>('A') << endl;

	char ch(97);
	cout << ch << endl;
	cout << static_cast<int>(ch) << endl;
	cout << ch << endl;

	cin >> c1; // �� ���� �� ���ڸ� �Է��ص� �� ���ڹۿ� �� �޴´�, �������� ���ۿ� �����
	cout << c1 << " " << static_cast<int>(c1) << endl;

	cout << sizeof(unsigned char) << endl;
	cout << (int)std::numeric_limits<unsigned char>::max() << endl;
	cout << (int)std::numeric_limits<unsigned char>::min() << endl;
	cout << (int)std::numeric_limits<unsigned char>::lowest() << endl;

	cout << int('\n') << endl;
	cout << "This is first line \nsecond line\n";
	// \n�� ���� �����Ͱ� ���� �� �� ó���� ���� ���ϰ� ���ۿ� ��ԵǴ� ��찡 �ִµ�
	// endl; �� ���� ������ �� ����ϰ� ���� �ٲٴ� ���̰� �ִ�
	cout << "This is first line " << std::flush; // �ٹٲ��� �� �ϰ�, ���ۿ� �ִ� �� �� ��Ƴ��� (������ �� ����Ѵ�)
	cout << "second line";
	
	wchar_t c;
	char16_t c3;
	char32_t c4;

	return 0;
}