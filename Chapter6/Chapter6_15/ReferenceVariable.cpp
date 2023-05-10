#include <iostream>

using namespace std;

void doSomething(const int& n) // 이렇게 받으면 이 함수 내에서 값이 바뀔 때
{								// 로컬영역임에도 불구하고 값이 같이 바뀐다
	// parameter에 포인터로 넣을 때에는 주소를 복사해야하는데
	// ref(참조변수)로 넣을 때에는 주소를 복사하는 과정조차 필요없어서(변수 자체가 들어감) 효율이 더 높고 속도가 더 빠르다
	cout << &n << endl;
	// n = 10; parameter로 const를 받아서 값을 바꿀 수 없게 됨
	cout << "In doSomething" << n << endl;
}

void printElements(int(&arr)[5]) // array를 함수에 넣을 때도 ref를 사용할 수 있음
{								// 이 경우 사이즈를 동일하게 맞춰줘야 함
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

int main()
{
	int value = 5;
	int* ptr = nullptr; // 가짜 전화번호를 넣어주는 느낌?
	ptr = &value; // 이런식으로도 가능하다고 함

	int& ref = value; // ref는 반드시 선언과 동시에 초기화가 되어야 한다
	// ref에는 리터럴은 못 들어간다, 변수만 넣을 수 있음
	// ref에서 값을 맘대로 바꿔버릴 수 있기 때문에 컴파일러가 허용을 안 함

	cout << ref << endl;
	ref = 10; // *ptr = 10; 처럼 작동하고 있다, 재할당 가능
	cout << value << " " << ref << endl;
	cout << &value << " " << &ref << " " << ptr << " " << &ptr << endl;

	int x = 7;
	int& ref_x = x;

	const int y = 8;
	const int& ref_y = y; // 상수는 const를 붙여주면 넣을 수 있어짐

	int n = 20;
	cout << n << endl;
	cout << &n << endl;

	doSomething(n);
	cout << n << endl;

	const int length = 5;
	int arr[length] = { 1, 2, 3, 4, 5 };

	printElements(arr);

	Other ot;
	int &v1 = ot.st.v1; // 이렇게 접근했어야 했는데, 이 때 ref를 쓰면
	v1 = 1; // 변수명이 매우 짧아지는 장점이 있다, 속도 저하도 없음

	int val = 5;
	int* const ptr_v = &val;
	int& ref_v = val; // 이 때 참조변수와 포인터는 기능상 완전히 동일하다

	*ptr_v = 10;
	ref_v = 10; // ref도 내부적으로는 포인터로 구현이 되어있음

	return 0;
}