#include <iostream>
#include <string>
#include <limits>

int main()
{
	using namespace std;

	const char my_strs[] = "Hello, World";
	const string my_hello("Hello, World");

	string my_ID = "123";
	cout << my_hello << endl;

	cout << "Your age ? : ";
	int age;
	cin >> age;
	//cin.ignore(32767, '\n'); // �Է��� �� �� ����� ���� �ֱ� ������
	// 2����Ʈ int�� ǥ���� ������ ���� ū signed ��(32767)�� �־��� ��
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Your name ? : ";
	string name;
	//cin >> name; ���⳪ ���Ͱ� ���� �Է��� ��ģ ������ �����ϰ� ���� �Է¿� ������ ��ģ��
	getline(cin, name);

	/*cout << "Your age ? : ";
	string age;
	//cin >> age;
	getline(cin, age); // ���͸� ġ���������� �Է��� �� ����*/

	cout << name << " " << age << endl;

	string a("Hello, ");
	string b("World ");
	string hw = a + b; // append
	hw += "I'm good";
	cout << hw << endl;

	string k = "Hello, World";
	cout << k.length() << endl;

	return 0;
}