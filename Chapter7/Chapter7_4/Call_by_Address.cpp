#include <iostream>

using namespace std;

typedef int* pint;

void foo(pint ptr) // 새로운 포인터를 선언하고 &value를 복사해서
{					// 초기화 시키고 생성한 것 <- 로컬포인터임
	cout << *ptr << " " << ptr << " " << &ptr << endl;
	*ptr = 10; // 포인터를 사용하여 함수의 return(출력)인 것처럼 사용하기도 한다
}

void ptr_like_ref(double degrees, double* sin_out, double* cos_out) // 포인터를 사용하는 건, 약간 C-Style이라고 한다
{	// 포인터를 이용하여 ref를 사용한 것과, 동일하게 작동시킬 수 있다
	*sin_out = 1; // <- 메모리 주소를 찾아가서 그 값을 바꿔주는 것
	*cos_out = 2; // 값을 바꿔줄 수 있다고 해서, ptr을 ref로 착각해서는 안 된다
	// 포인터라는 것은, 내부적으로는 call by value를 사용한다는 점을 잊으면 안 된다
}

void printArray(const int* const ptr, int* arr, int length)
{ // parameter로 포인터가 들어올 때 const int까지는 많이 하지만
	// const int const ptr까지는 안 한다, ptr이 바뀐다고 해서
	// 바깥의 다른 영역의 값들이 바뀌는 건 아니기 때문에, const를 굳이 안 붙이는 것
	// 다만, 구현하거나 할 때 실수를 줄이기 위해 붙이는 경우는 있음
	for (int i = 0; i < length; ++i)
		cout << arr[i] << endl;
	arr[0] = 10; // []가 사실은 *&(역참조)랑 똑같은 거였다 !!!
}

// parameter로 데이터를 엄청 많이 담고있는 배열을 받을 때
// 주소 하나를 복사하는 정도는, 그 수많은 데이터를 모두 복사하는 것보다 훨씬 효율이 높다
// 그런 이유에서 포인터를 사용했었는데, 최근에는 점점 ref로 교체되고 있다
// C와 C++의 차이

int main()
{
	int value = 5;
	cout << value << " " << &value << endl;
	int* ptr = &value;
	cout << &ptr << endl;
	foo(ptr);
	cout << value << endl;
	foo(&value);
	//foo(5); 리터럴은 안 된다

	double degrees(30);
	double sin, cos;					// parameter로 포인터를 받을 때는
	ptr_like_ref(degrees, &sin, &cos); // &를 붙여서 넣어주거나, ptr로 넣어줘야 함
	cout << sin << " " << cos << endl;
	// 실용적인 면에서는 ptr보다 ref를 쓰는 게 더 편하다고 함

	return 0;
}