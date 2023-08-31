#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	{
		stringstream os;

		os << "Hello, World!"; // << : insertion operator, >> : extraction operator
		os << "Hello, World!2" << endl; // endl도 stringstream에 들어가짐
		//os.str("Hello, World!\n"); // 이렇게 넣을 수도 있음, buffer에 넣어준 것, '\n'도 포함시킬 수 있음
		// os.str()은 현재 buffer에 있는 내용을 통째로 바꿔버림

		string str;
		//os >> str; // buffer에 들어있는 걸 str에 넣어주고 있음, " "가 있으면 잘려버림
		str = os.str(); // buffer에 들어있는 걸 통째로 가져옴
		cout << str << endl;
		cout << os.str() << endl;
	}

	{
		stringstream os;
		//os << "12345 67.89";
		/*int i = 12345;
		double d = 67.89;
		// 숫자를 넣어서 << 숫자로 받는 >> 것도 문제없이 잘 되고
		os << i << " " << d;*/ // stream은 전반적으로 " "를 구분자로 쓴다
		
		// 문자를 넣어서 << 숫자로 받는 >> 것도 마찬가지로 잘 작동한다
		os << "12345 67.89";
		//int i2;
		//double d2;
		//os >> i2 >> d2; 
		//cout << i2 << "|" << d2 << endl;

		//os.str(""); // 이렇게 하면 stream을 비워버릴 수 있다
		//os.str(string()); // 이렇게 지우는 방법도 있다
		os.clear(); // 이런 것도 있는데 뭔가 이상하다
		os << "Hello";
		cout << os.str() << endl;

		/*string str1;
		string str2;
		os >> str1 >> str2;
		cout << str1 << "|" << str2 << endl;*/
	}

	return 0;
}