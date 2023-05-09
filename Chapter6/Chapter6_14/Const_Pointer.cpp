#include <iostream>

using namespace std;

int main()
{
	int value = 5;
	const int* ptr = &value; // 주소를 가져와서 저장하고, 값을 읽는 작업은 가능함
	// *ptr = 6; value가 const로 바뀌면서 값을 못 바꾸게 됨
	value = 6; // value가 const가 아니고, pointer만 const일 경우 value의 값을 바꾸는 건 문제 없음
	
	cout << *ptr << endl;

	int value1 = 5;
	const int* ptr2 = &value1;
	int value2 = 6;
	ptr2 = &value2; // 이건 또 되네, 역참조로 값을 안 바꾸겠다는 것이지, 주소 자체는 바꿀 수 있음

	int val = 5;
	int* const ptr3 = &val; // 이 경우, 역참조로 값을 바꾸는 건 되는데, 주소는 바꿀 수 없음
	*ptr3 = 15;
	cout << *ptr3 << endl;

	int val2 = 5;
	const int* const ptr4 = &val2; // 포인터가 상수일 때, (const ptr)일 때는 주소값을 선언과 동시에 초기화 해주지 않으면 안 됨
	cout << *ptr4 << endl;

	int v = 5;
	const int* ptr_1 = &v; // 한 변수(하나의 주소)에 포인터가 여러개 붙을 수도 있음 <- 문제 없다
	int* const ptr_2 = &v;
	const int* const ptr_3 = &v;

	return 0;
}