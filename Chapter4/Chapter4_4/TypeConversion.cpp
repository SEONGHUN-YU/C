#include <iostream>
#include <typeinfo>
#include <iomanip> // setprecision()을 위해 가져옴

int main()
{
	using namespace std;

	// type casting을 해주면 (int)등, 명시적 형변환이다
	// 암시적 형변환은 그렇지 않은 경우를 말하고
	// 크게 2가지가 있다
	// 1. numeric promotion
	float a = 1.0f;
	double d = a; // 작은 것을 큰 것으로

	// 2. numeric conversion <- 문제가 발생할 수 있음
	double dd = 3; // 타입이 바뀌거나 OR
	short s = 2; // 큰 것을 작은 것으로

	int i = 30000;
	char c = i;
	cout << static_cast<int>(c) << endl;

	double ddd = 0.123456789;
	float f = ddd;
	cout << setprecision(12) << f << endl;

	int ii = 1234;
	float ff = ii;
	cout << setprecision(12) << ff << endl;

	float fff = 3.14;
	int iii = fff;
	cout << setprecision(12) << iii << endl;

	cout << 5u - 10u << endl; // 이상하게 나옴
	// 형변환에는 우선순위가 있는데
	// int, unsigned int, long, unsigned long
	// long long, unsigned long long, float, double, long double
	// int가 우선순위가 가장 낮고, long double이 우선순위가 가장 높다

	int k = int(4.0); // c++스타일
	int kk = (int)4.0; // c스타일
	int kkk = static_cast<int>(4.0); // 최근에 쓰는 더 좋은 방법?
	// 셋 다 기능상 차이는 없다는 듯 ?

	int n = 123;
	cout << typeid(n).name() << endl;
	cout << typeid(4.0).name() << endl;

	return 0;
}