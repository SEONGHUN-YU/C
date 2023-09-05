#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main()
{
	const string filename = "my_file.txt";

	// make a file : writing 하는 중
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;
	}

	// read the file
	//{
	//	ifstream ifs(filename);

	//	// 5bytes를 이동해라(무시, 지나침)
	//	ifs.seekg(5); // ifs.seekg(5, ios::beg);
	//	cout << (char)ifs.get() << endl; // 한 글자만 읽어옴

	//	ifs.seekg(5, ios::cur); // 현재 커서에서 5bytes를 이동해라
	//	cout << (char)ifs.get() << endl;

	//	//ifs.seekg(-5, ios::end);

	//	/*ifs.seekg(0, ios::end); // 마지막 위치로 감
	//	cout << ifs.tellg() << endl;*/ // 현재 위치(몇 번째 글자인지)를 int로 알려줌

	//	string str;
	//	getline(ifs, str); // 한 줄씩 가져옴
	//	cout << str << endl;
	//}

	{
		//fstream iofs(filename, ios::in | ios::out); // 이렇게 flag를 설정해서 써도 됨
		fstream iofs(filename);

		iofs.seekg(5);
		cout << (char)iofs.get() << endl; // read

		iofs.seekg(5);
		iofs.put('A'); // write
		// 글자가 이미 있다면, insert가 되는 게 아니라 덮어씌워짐
	}

	return 0;
}