#include <iostream>
#include <string>
#include <cctype> // is시리즈가 들어 있음, isalpha, isdigit, isalnum, islower, isupper, tolower, toupper는 꼭 알아두자
#include <bitset>

using namespace std;

void printCharacterClassification(const int& i)
{
	cout << boolalpha;
	cout << "isalnum " << bool(std::isalnum(i)) << endl;
	cout << "isblank " << bool(std::isblank(i)) << endl;
	cout << "isdigit " << bool(std::isdigit(i)) << endl;
	cout << "islower " << bool(std::islower(i)) << endl;
	cout << "isupper " << bool(std::isupper(i)) << endl;
}

void printStates(const std::ios& stream)
{
	cout << boolalpha;
	cout << "good()=" << stream.good() << endl; // bool로 return
	cout << "eof()=" << stream.eof() << endl; // end of file인지 bool로 return
	cout << "fail()=" << stream.fail() << endl; // 읽어오는데 실패했는지 bool로 return, good의 반대라고 봐도 무방한가?
	cout << "bad()=" << stream.bad() << endl; // 잘 읽다가 문제가 생기면 true로 세팅이 됨
}

bool isAllDigit(const string& str)
{
	bool ok_flag = true;
	for (auto e : str)
		if (!std::isdigit(e))
		{
			ok_flag = false;
			break;
		}
	return ok_flag;
}

void classifyCharacters(const string& str)
{
	for (auto e : str)
	{
		cout << e << endl;
		cout << "isdigit " << std::isdigit(e) << endl;
		cout << "isblank " << std::isblank(e) << endl;
		cout << "isalpha " << std::isalpha(e) << endl;
	}
}

int main()
{
	//while (true)
	//{
	//	char i;
	//	cin >> i;

	//	printStates(cin);

	//	//cout << i << endl;

	//	/*cout << boolalpha;
	//	cout << std::bitset<8>(cin.rdstate()) << endl; // 현재의 flag상태가 int로 나옴
	//	cout << std::bitset<8>(std::istream::goodbit) << endl; // mask
	//	cout << std::bitset<8>(std::istream::failbit) << endl; // mask
	//	cout << !bool((cin.rdstate() & std::istream::failbit) != 0) << endl;*/
	//	//cin.rdstate() == std::istream::goodbit; 이렇게 할 수도 있다는데 좀 복잡한듯
	//	// mask를 이용해서 & 비트연산으로 현재 상태를 추출하는 것
	//	// 이런 식으로 bit masking을 사용해서 체크할 수도 있지만
	//	// 일반적으로는 printStates()처럼 구현하는 게 편할 것
	//	// 다만 퍼포먼스는 압도적으로 bit masking이 빠르다

	//	printCharacterClassification(i);

	//	cin.clear();
	//	cin.ignore(1024, '\n');
	//	cout << endl;
	//}

	{
		cout << boolalpha;
		//cout << isAllDigit("1234") << endl;
		//cout << isAllDigit("a1234") << endl;

		classifyCharacters("1234");
		classifyCharacters("a 1234");

		// regular expression을 쓰면 편하다
	}

	return 0;
}