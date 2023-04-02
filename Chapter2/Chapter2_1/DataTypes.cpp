#include <iostream>

using namespace std;

int main()
{
	// fundamental data types, built-in data types 라고도 부른다, 기본형들

	// char, char16_t, char32_t, wchar_t #1
	// signed -> char, short, int, long, long long #2
	// unsigned -> char, short, int, long, long long #3
	
	// char은 Character타입이기도 하고 Integer타입이기도 하다
	// 저장할 때 내부적으로 정수로 저장하기 때문
	// (signed) short (int)처럼 풀네임으로 써도 전혀 상관없다고 함

	// float, double, long double #4
	// bool #5
	// void #6 나중에 포인터에서 보이드 포인터라는 게 나오니 중요하다고 함
	// decltype(nullptr) #7 널 포인터

	bool bVal = false;
	// char cVal = 'A'; // #A
	char cVal = 65;		// #B
	float fVal = 3.141592f; // float은 마지막 자리에 f를 붙인다, 안 붙이면 double로 취급해서 warning 뜸
	double dVal = 3.141592;

	auto aVal = 3.141592; // 모던 C++에 있는 타입, 컴파일할 때 자료형이 정해진다
	auto aVal2 = 3.141592f; // 오토 디덕션

	// cout << (bVal ? 1 : 0) << endl;
	cout << bVal << endl; // 0이 나옴
	// cout << (int)cVal << endl;	// #A일 때 65이 나옴
	cout << cVal << endl;			// #B일 때 'A'이 나옴
	cout << fVal << endl;
	cout << dVal << endl;
	cout << sizeof(aVal) << endl;
	cout << sizeof(aVal2) << endl;

	cout << sizeof(bool) << endl; // sizeof()에는 타입을 넣어도 되고
	cout << sizeof(bVal) << endl; // 식별자를 넣어도 된다

	int a = (int)123.1; // copy initialization
	int b((int)123.1);	// direct initialization
	int c{ 123 }; // uniform initialization <- 조금 더 엄격하다
	int k = 0, l(123), m{ 456 }; // k, l = 123, m; 처럼, 특정값만 초기화 시켜줄 수도 있다

	// 최근에는 사용할 변수를, 사용하기 직전에 선언과 동시에 초기화 시키는 방식을 선호한다

	return 0;
}