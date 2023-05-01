#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	// C��Ÿ�� �ڵ�, �������� ���
	char source[] = "Copy this!";
	char dest[50];
	strcpy_s(dest, 50, source); // string copy secured �� �ظ�
	cout << source << endl;
	cout << dest << endl;

	// strcat() : concat�̶� ����
	// strcmp() : equals�� ���� ��?

	strcat_s(dest, source);
	cout << source << endl;
	cout << dest << endl;

	cout << strcmp(dest, source) << endl; // bool�� return, ���� ��, ������ 0�� return ���� !!
	if (strcmp(dest, source) == 0); // true�� �� 0�� ��ȯ��, �� ������ == 0 �̶�� �Ҹ�



	char myString[] = "string"; // '\0' null character�� ������ ����

	for (int i = 0; i < 7; i++)
	{
		cout << (int)myString[i] << " ";
	}
	cout << endl;
								// �μ��� char�� �־ ��
	cout << sizeof(myString) / sizeof(myString[0]) << endl;

	char str[255];
	// cin >> str;									
	cin.getline(str, 255);						// �� ĭ�ϰ�� �ٸ� ����
	// cout << str << endl; // cout�� ����� �ϴٰ� '\0'�� ������ ����� �ߴ��ع�����

	int ix = 0;
	while (true)
	{
		if (str[ix] == '\0') break;
		cout << str[ix] << " " << (int)str[ix] << endl;
		++ix;
	}

	return 0;
}