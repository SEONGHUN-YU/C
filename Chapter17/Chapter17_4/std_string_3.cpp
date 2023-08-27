#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string my_str("abcdefg");

	cout << my_str[0] << endl;
	cout << my_str[3] << endl;

	//my_str[3] = 'Z'; // []로 접근하면 char로 넣어줘야 함

	cout << my_str << endl;

	try
	{
		//my_str[100] = 'X'; // 런타임 에러, 근데 try-catch로 못 잡음
		my_str.at(100) = 'X'; // .at()으로 접근하면 throw를 해주기 때문에 잡아줌
		// []는 퍼포먼스, .at()은 안정성 추구
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}

	const char* arr = my_str.c_str(); // .c_str()로 가져오면 null character를 붙여서 준다
	const char* arr2 = my_str.data(); // .c_str() == .data() 라고 봐도 무방

	cout << my_str.c_str() << endl;
	cout << my_str.c_str()[6] << " 또는 " << arr[6] << endl;
	cout << (int)arr[6] << endl;
	cout << (int)arr[7] << endl; // null character의 아스키 코드

	char buf[20];
	my_str.copy(buf, 5, 1); // buf에 복사, 5글자를, 1칸 밀어서
	buf[5] = '\0'; // null character를 수동으로 넣어줌, 이젠 쓰레기값이 안 나옴
	cout << buf << endl; // 복사가 되긴 되는데 null character를 자동으로 넣어주지 않아서 쓰레기값도 같이 나옴

	return 0;
}