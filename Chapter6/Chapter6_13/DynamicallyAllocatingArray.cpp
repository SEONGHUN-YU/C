#include <iostream>

using namespace std;

int main()
{
	// 정적 배열은 배열의 사이즈가 컴파일 타임에 결정이 되어있어야만 사용할 수 있었는데
	// 동적 배열은 런타임에 배열의 사이즈를 결정할 수 있다
	// 그때그때 메모리를 OS로부터 받아오기 때문에 좀 더 유동적인 것

	//int array[length]; 정적 배열
	int length;
	cin >> length;
	int* array = new int[length] {}; // 동적 배열, new를 써서 만드는 게 핵심
	// 모든 값을 0으로 초기화 하고 싶을 때에는 []뒤에 () 또는 {} 를 붙임
	// {값, 값, ...} 으로도 초기화 가능, 할당되지 않은 나머지 들은 0이 됨
	// 런타임에 배열의 사이즈를 결정할 때, 초기화 시키는 갯수보다 사이즈가 적으면 메모리 충돌로 인한 에러가 남
	for (int i = 0; i < length; i++)
	{
		cout << (uintptr_t) & array[i] << " " << array[i] << endl;
	}
	delete[] array;

	int fixedArray[] = { 1,2,3,4,5 };
	int* array_test = new int[3] {1, 2, 3};
	delete[] array_test;
	// 배열 사이즈 resizing : 직접적으론 안 됨
	// 다른 더 큰 메모리를 받아온 다음에, 원래 가지고 있던 것들을 복사해서 집어넣고
	// 그 뒤에 새로 추가가 될 것들을 덧붙여주는 식으로 해야 함
	// 하지만 정적 배열은 아예 시도조차 못 함, 그에 비하면 나은 것

	// 저 작업을 vector는 다 가능함, vector를 배우자

	return 0;
}