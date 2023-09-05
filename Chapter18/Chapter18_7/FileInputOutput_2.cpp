#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main()
{
	const string filename = "my_file.txt";

	// make a file : writing �ϴ� ��
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;
	}

	// read the file
	//{
	//	ifstream ifs(filename);

	//	// 5bytes�� �̵��ض�(����, ����ħ)
	//	ifs.seekg(5); // ifs.seekg(5, ios::beg);
	//	cout << (char)ifs.get() << endl; // �� ���ڸ� �о��

	//	ifs.seekg(5, ios::cur); // ���� Ŀ������ 5bytes�� �̵��ض�
	//	cout << (char)ifs.get() << endl;

	//	//ifs.seekg(-5, ios::end);

	//	/*ifs.seekg(0, ios::end); // ������ ��ġ�� ��
	//	cout << ifs.tellg() << endl;*/ // ���� ��ġ(�� ��° ��������)�� int�� �˷���

	//	string str;
	//	getline(ifs, str); // �� �پ� ������
	//	cout << str << endl;
	//}

	{
		//fstream iofs(filename, ios::in | ios::out); // �̷��� flag�� �����ؼ� �ᵵ ��
		fstream iofs(filename);

		iofs.seekg(5);
		cout << (char)iofs.get() << endl; // read

		iofs.seekg(5);
		iofs.put('A'); // write
		// ���ڰ� �̹� �ִٸ�, insert�� �Ǵ� �� �ƴ϶� �������
	}

	return 0;
}