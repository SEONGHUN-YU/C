#include <iostream>

using namespace std;

int main()
{
	// void my_void; 보이드는 메모리를 차지하지 않기 때문에 선언할 수 없다

	int i = 123;
	float f = 123.456f;

	void* my_void;

	my_void = (void*)&i; // 나중에 배우게 될 보이드 포인터 맛보기
	my_void = (void*)&f; // 아직 자세하게 다루지 않음

	return 0;
}