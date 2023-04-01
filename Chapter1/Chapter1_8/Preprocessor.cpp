#include <iostream>
#include <algorithm> // max 함수를 위해 가져옴

using namespace std;

// #define MY_NUMBER "hello world" // 식별자를 만나면, 뒤에 것으로 교체해버림
// 문서편집기 같은 느낌이다, 전처리기의 식별자명은 모두 대문자를 쓰는 것이 관례
// 전처리기는 매크로 라고도 부르는 듯?
#define MAX(a, b) (a > b ? a : b)
// #define MAX(a, b) (((a) > (b)) ? (a) : (b)) 이렇게 써도 위의 코드랑 같은 동작을 한다
#define LIKE_APPLE // #define은 현재 이 cpp파일 내에서만 효과가 적용된다

int main()
{
	cout << MAX(25, 50) << endl;
	cout << std::max(10 + 30, 20) << endl;

// 전처리기는 빌드 들어가기 전에 처리한다
// 응용하면, 윈도우인지 리눅스인지에 따라 다르게 실행한다던지 하는 것이 가능
// conditional compilation 라고 부른다
#ifdef LIKE_APPLE
	cout << "Apple" << endl;
#endif
	// #else로 처리하는 방법도 있음, #ifdef - #else - #endif
#ifndef LIKE_APPLE
	cout << "Orange" << endl; // 조건에 맞지 않아서 전처리기에 의해 흐리게 된 코드
#endif

	return 0;
}