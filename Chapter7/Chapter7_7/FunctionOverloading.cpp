#include <iostream>
#include <string>

using namespace std;

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

// return 타입이 다른 것만 가지고는 overloading 불가능
// parameter가 달라야 함, return 타입은 같아도 상관 없음
// typedef를 쓰더라도 안 됨, 컴파일러에게 눈속임이 안 통함

// parameter가 같을 때, 충돌을 회피하는 방법
// 1. 함수 이름을 바꾼다
// 2. void 함수에 parameter로 ref를 받아서 간접 return을 구현한다

// 매치가 정확히 안 될 때가 있음 <- 중요한 문제 ★
//void print(char* x) {} // 'a'를 int로 인식해버림
//void print(int x) {}

void print(unsigned int value) {}
void print(float value) {}

int main()
{
	add(1, 2); // 오버로딩된 함수 중에서, 어느 함수를 호출할 지는
	add(3.0, 4.0); // 컴파일되기 전에 확실히 결정되어 있어야 한다 -> 이걸 만족해야만 컴파일을 함

	print(unsigned int('a')); // 이런 식으로 명확히 하면, 모호성이 해소가 된다
	print(0u);
	print(3.14159f);

	return 0;
}