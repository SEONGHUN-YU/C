#include <iostream>
#include <string>
#include <cctype> // is�ø�� ��� ����, isalpha, isdigit, isalnum, islower, isupper, tolower, toupper�� �� �˾Ƶ���
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
	cout << "good()=" << stream.good() << endl; // bool�� return
	cout << "eof()=" << stream.eof() << endl; // end of file���� bool�� return
	cout << "fail()=" << stream.fail() << endl; // �о���µ� �����ߴ��� bool�� return, good�� �ݴ��� ���� �����Ѱ�?
	cout << "bad()=" << stream.bad() << endl; // �� �дٰ� ������ ����� true�� ������ ��
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
	//	cout << std::bitset<8>(cin.rdstate()) << endl; // ������ flag���°� int�� ����
	//	cout << std::bitset<8>(std::istream::goodbit) << endl; // mask
	//	cout << std::bitset<8>(std::istream::failbit) << endl; // mask
	//	cout << !bool((cin.rdstate() & std::istream::failbit) != 0) << endl;*/
	//	//cin.rdstate() == std::istream::goodbit; �̷��� �� ���� �ִٴµ� �� �����ѵ�
	//	// mask�� �̿��ؼ� & ��Ʈ�������� ���� ���¸� �����ϴ� ��
	//	// �̷� ������ bit masking�� ����ؼ� üũ�� ���� ������
	//	// �Ϲ������δ� printStates()ó�� �����ϴ� �� ���� ��
	//	// �ٸ� �����ս��� �е������� bit masking�� ������

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

		// regular expression�� ���� ���ϴ�
	}

	return 0;
}