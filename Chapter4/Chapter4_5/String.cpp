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
	//cin.ignore(32767, '\n'); // 입력을 할 때 길게할 수도 있기 때문에
	// 2바이트 int로 표현이 가능한 가장 큰 signed 값(32767)을 넣어준 것
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Your name ? : ";
	string name;
	//cin >> name; 띄어쓰기나 엔터가 들어가면 입력을 마친 것으로 간주하고 다음 입력에 영향을 미친다
	getline(cin, name);

	/*cout << "Your age ? : ";
	string age;
	//cin >> age;
	getline(cin, age); // 엔터를 치기전까지의 입력이 다 들어간다*/

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