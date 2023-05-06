#include <iostream>

using namespace std;

//void printArray(int array[])
void printArray(int *array)
{
	cout << sizeof(array) << endl;
	cout << *array << endl;

	*array = 100;
}

struct MyStruct
{
	int array_t[5] = { 10, 20, 30, 40, 50 };
};

void doSomething(MyStruct ms)
{
	cout << sizeof(ms.array_t) << endl;
}

void doSomething_ptr(MyStruct *ms) // 배열이 struct나 class안에 들어있을 경우에는
{									// pointer로 강제변환이 되지 않음
	cout << sizeof((*ms).array_t) << endl;
}

int main()
{
	// 포인터와 정적배열은 결과적으로 같다
	// 함수의 parameter로 정적배열을 집어넣을 때에는
	// 함수에서 받아들이면서 포인터로 바꿔버리기 때문에, 정적배열로써 쓸 수는 없다
	MyStruct ms;
	cout << ms.array_t[0] << endl;
	cout << sizeof(ms.array_t) << endl;

	doSomething(ms);
	doSomething_ptr(&ms);

	int array[5] = { 9,7,5,3,1 };

	cout << array[0] << " " << array[1] << endl;
	cout << array << endl;
	cout << &array[0] << endl;
	
	cout << *array << endl;
	cout << sizeof(array) << endl; // 20

	int* ptr = array;
	cout << sizeof(ptr) << endl; // pointer

	// pointer arithmetic : 포인터 연산
	cout << *ptr << " " << *(ptr + 1) << endl; 

	char name[] = "oh yeah";
	cout << (char)(*name + 1) << endl;

	printArray(array);

	cout << array[0] << " " << *array << endl;

	return 0;
}

