#include <iostream>
#include <string>

using namespace std;

int main()
{
	{
		string str1("one");
		string str2;
		str2 = str1;
		str2 = "two";
		str2.assign("two").append(" ").append("three ").append("four");
		cout << str2 << endl;
	}

	{
		string str1("one");
		string str2("two");
		cout << str1 << " " << str2 << endl;
		std::swap(str1, str2);
		cout << str1 << " " << str2 << endl;
		str1.swap(str2);
		cout << str1 << " " << str2 << endl;

		str1.append("three");
		str1.push_back('A'); // char¸¸ °¡´É
		str1 += "three";
		str1 = str2 + "four";
		str1.insert(2, "five");
		cout << str1 << endl;
	}

	return 0;
}