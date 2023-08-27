#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string my_str("abcdefg");

	cout << my_str[0] << endl;
	cout << my_str[3] << endl;

	//my_str[3] = 'Z'; // []�� �����ϸ� char�� �־���� ��

	cout << my_str << endl;

	try
	{
		//my_str[100] = 'X'; // ��Ÿ�� ����, �ٵ� try-catch�� �� ����
		my_str.at(100) = 'X'; // .at()���� �����ϸ� throw�� ���ֱ� ������ �����
		// []�� �����ս�, .at()�� ������ �߱�
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}

	const char* arr = my_str.c_str(); // .c_str()�� �������� null character�� �ٿ��� �ش�
	const char* arr2 = my_str.data(); // .c_str() == .data() ��� ���� ����

	cout << my_str.c_str() << endl;
	cout << my_str.c_str()[6] << " �Ǵ� " << arr[6] << endl;
	cout << (int)arr[6] << endl;
	cout << (int)arr[7] << endl; // null character�� �ƽ�Ű �ڵ�

	char buf[20];
	my_str.copy(buf, 5, 1); // buf�� ����, 5���ڸ�, 1ĭ �о
	buf[5] = '\0'; // null character�� �������� �־���, ���� �����Ⱚ�� �� ����
	cout << buf << endl; // ���簡 �Ǳ� �Ǵµ� null character�� �ڵ����� �־����� �ʾƼ� �����Ⱚ�� ���� ����

	return 0;
}