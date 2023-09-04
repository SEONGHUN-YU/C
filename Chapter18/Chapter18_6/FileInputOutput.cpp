#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib> // exit()

using namespace std;

int main()
{
	// writing
	if (1)
	{										// append
		ofstream ofs("my_first_file.dat", ios::app); // ios::app, ios::binary
		//ofs.open("my_first_file.dat"); // 작업할 파일을, 이렇게 가져올 수도 있음

		if (!ofs)
		{
			cerr << "Couldn't open file" << endl;
			exit(1);
		}

		ofs << "Line 1" << endl; // ascii방식으로 저장함
		ofs << "Line 2" << endl;

		/*const unsigned num_data = 10;
		ofs.write((char*)&num_data, sizeof(num_data));

		for (int i = 0; i < num_data; ++i)
			ofs.write((char*)&i, sizeof(i));*/ // binary방식으로 저장함

		/*stringstream ss; // JSON처럼 문자열 한 줄로 다 담는 경우에 쓰는 방식
		ss << "Line 1" << endl;
		ss << "Line 2" << endl;
		string str = ss.str();

		unsigned str_length = str.size();
		ofs.write((char*)&str_length, sizeof(str_length));
		ofs.wirte(str.c_str(), str_length);*/

		//ofs.close(); // not necessary, 블록 나가면서 알아서 닫아준다는 듯 함
	}

	// reading
	if (0)
	{
		ifstream ifs("my_first_file.dat");
		
		if (!ifs)
		{
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		while (ifs)
		{
			string str;
			getline(ifs, str); // ascii방식으로, 한 줄씩 읽어들임
			cout << str << endl;
		}

		/*unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));

		for (unsigned i = 0; i < num_data; ++i)
		{
			int num;
			ifs.read((char*)&num, sizeof(num)); // binary방식으로 읽어들임
			cout << num << endl;
		}*/

		/*unsigned str_len = 0; // JSON처럼 문자열 한 줄에 다 담긴 경우에 쓰는 방식
		ifs.read((char*)&str_len, sizeof(str_len));

		string str;
		str.resize(str_len);
		ifs.read(&str[0], str_len);

		cout << str << endl;*/

		//ifs.close(); // not necessary
	}

	return 0;
}