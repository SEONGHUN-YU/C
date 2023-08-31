#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	{
		cout.setf(std::ios::showpos); // setflag
		cout << 108 << endl;
		cout.unsetf(std::ios::showpos);
		cout << 109 << endl;
	}

	{
		//cout.unsetf(std::ios::dec); // 10진수 모드를 끄고 해야 함
		//cout.setf(std::ios::hex); // 16진수출력
		//cout.setf(std::ios::hex, std::ios::basefield); // 다른 방법으로는 이렇게
		//cout.setf(std::iostream::uppercase); // 16진수의 알파벳을 대문자로 나오게 해줌
		
		cout << std::hex << std::uppercase; // 이렇게도 된다, iomanip을 사용 중
		cout << 108 << endl; // 그럼 16진수로 나옴
		cout << 109 << endl;

		cout << std::dec; // 다시 10진수로 돌아감
		cout << 110 << endl;
	}

	{
		cout << std::boolalpha; // bool을 글자로 나오게 해줌
		cout << true << " " << false << endl;
	}

	{
		//cout << std::defaultfloat; 이게 기본값으로 되어 있음
		//cout << std::fixed; // 얘는 반올림을 안 하고, 있는 그대로 출력함
		//cout << std::scientific << std::uppercase;
		cout << std::showpoint; // defalut 느낌인데 .을 무조건 출력함
		cout << std::setprecision(3) << 123.456 << endl; // 반올림해서 출력함
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
	}

	{
		std::cout << -12345 << endl;
		cout.fill('*'); // 빈칸을 채워줌
		cout << std::setw(10) << -12345 << endl; // 남는만큼 뒤로 붙음
		cout << std::setw(10) << std::left << -12345 << endl;
		cout << std::setw(10) << std::right << -12345 << endl;
		cout << std::setw(10) << std::internal << -12345 << endl; // 남는만큼 중간에 공백 생김
	}

	return 0;
}