#include <iostream>
#include <limits>

using namespace std;

int main()
{
	char c1(65);
	char c2('A');

	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;
	
	// c-style casting
	cout << (char)65 << endl;
	cout << (int)'A' << endl;

	// cpp style casting
	cout << char(65) << endl;
	cout << int('A') << endl;

	// 위의 2개 방식은 강제변환시키는 느낌이 강하고
	// 아래 방식은 컴파일러에게, 현재 이 캐스팅이 문제가 없을지 물어보는 느낌이 강하다

	cout << static_cast<char>(65) << endl; // 협업에서 캐스팅중인 것을 강조할 때도 쓰이는 듯하다
	cout << static_cast<int>('A') << endl;

	char ch(97);
	cout << ch << endl;
	cout << static_cast<int>(ch) << endl;
	cout << ch << endl;

	cin >> c1; // 한 번에 두 글자를 입력해도 한 글자밖에 못 받는다, 나머지는 버퍼에 저장됨
	cout << c1 << " " << static_cast<int>(c1) << endl;

	cout << sizeof(unsigned char) << endl;
	cout << (int)std::numeric_limits<unsigned char>::max() << endl;
	cout << (int)std::numeric_limits<unsigned char>::min() << endl;
	cout << (int)std::numeric_limits<unsigned char>::lowest() << endl;

	cout << int('\n') << endl;
	cout << "This is first line \nsecond line\n";
	// \n을 쓰면 데이터가 많을 때 다 처리를 하지 못하고 버퍼에 담게되는 경우가 있는데
	// endl; 을 쓰면 무조건 다 출력하고 줄을 바꾸는 차이가 있다
	cout << "This is first line " << std::flush; // 줄바꿈을 안 하고, 버퍼에 있는 걸 다 쏟아낸다 (무조건 다 출력한다)
	cout << "second line";
	
	wchar_t c;
	char16_t c3;
	char32_t c4;

	return 0;
}