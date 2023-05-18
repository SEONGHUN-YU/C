#include <iostream>

using namespace std;

int foo(int x, int y);

int foo(int x, int y) // 변수들이 새로 선언되어 생성된다
{
	return x + y;
} // parameter에서 선언된 변수들이 함수가 종료됨과 동시에
// 메모리를 OS에 반납하며 사라지게 된다 <- parameter들은 로컬변수라는 소리

int main()
{
	int x = 1, y = 2;
	foo(6, 7); // arguments (actual parameters : 실 인자?)
	foo(x, y + 1);
	// 값에 의한 전달, 참조에 의한 전달, 주소에 의한 전달이 있다
	// call by value, call by reference
	return 0;
}