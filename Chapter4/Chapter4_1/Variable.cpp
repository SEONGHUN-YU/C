#include <iostream>
#include "MyConstants.h"

using namespace std;

int value = 123;

//void doSomething()
//{
//	// static int a = 1;
//	++a;
//	cout << a << endl;
//}

// forward declaration : 전방 선언
extern void doSomething(); // 원래는 extern이라는 키워드가 필요한데, 생략될 수 있는 것
extern int a;

/*
	int g_x; // external linkage <- 초기화가 안 된 전역 변수
	static int g_x; // internal linkage <- 초기화가 되지 않은, 다른 cpp파일에서 접근할 수 없는 정적 변수

	int g_y(1); 초기화가 된 전역 변수
	static int g_y(1); 초기화가 된 정적 변수
	const int g_y(1); 같은 파일 안에서만 접근할 수 있는 상수

	forward declaration일 경우
	extern int g_z; <- 다른 곳에서는 초기화가 되어있어야 함
	extern const int g_z; <- 마찬가지로, 다른 곳에서는 초기화가 되어있어야 함

	extern int g_w(1); <- 다른 곳에서는 초기화하면 안 됨
	extern const int g_w(1); <- 초기화가 된, 다른 cpp파일(외부)에서도 접근할 수 있는 상수
*/

int main()

{
	cout << "In main.cpp file " << Constants::pi << " " << &Constants::pi << endl;
 	doSomething();

	cout << a << endl;

	cout << value << endl;
	int value = 1;
	cout << ::value << endl; // global scope operator를 사용한 모습
	cout << value << endl;

	return 0;
}