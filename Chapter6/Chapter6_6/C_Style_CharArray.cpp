#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	// C스타일 코딩, 고전적인 방식
	char source[] = "Copy this!";
	char dest[50];
	strcpy_s(dest, 50, source); // string copy secured 의 준말
	cout << source << endl;
	cout << dest << endl;

	// strcat() : concat이랑 같다
	// strcmp() : equals랑 같은 듯?

	strcat_s(dest, source);
	cout << source << endl;
	cout << dest << endl;

	cout << strcmp(dest, source) << endl; // bool로 return, 웃긴 건, 같으면 0을 return 주의 !!
	if (strcmp(dest, source) == 0); // true일 때 0이 반환됨, 즉 같으면 == 0 이라는 소리



	char myString[] = "string"; // '\0' null character가 숨겨져 있음

	for (int i = 0; i < 7; i++)
	{
		cout << (int)myString[i] << " ";
	}
	cout << endl;
								// 인수에 char를 넣어도 됨
	cout << sizeof(myString) / sizeof(myString[0]) << endl;

	char str[255];
	// cin >> str;									
	cin.getline(str, 255);						// 빈 칸하고는 다른 거임
	// cout << str << endl; // cout이 출력을 하다가 '\0'를 만나면 출력을 중단해버린다

	int ix = 0;
	while (true)
	{
		if (str[ix] == '\0') break;
		cout << str[ix] << " " << (int)str[ix] << endl;
		++ix;
	}

	return 0;
}