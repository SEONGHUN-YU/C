#include <iostream>

using namespace std;

int main()
{
	// 이중포인터 기본 개념
	int* ptr = nullptr;
	int** ptrptr = nullptr;

	int value = 5;
	ptr = &value;
	ptrptr = &ptr;

	cout << ptr << " " << *ptr << " " << &ptr << endl;
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
	cout << **ptrptr << endl;

	// 동적 할당으로 다차원 배열 만들기
	// 이중포인터를 쓰는 방식, 안 쓰는 방식 2개가 있다
	const int row = 3;
	const int col = 5;

	const int s2da[row][col] =
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15}
	};

	/*int* r1 = new int[col] {1, 2, 3, 4, 5}; // for문 없이 초기화 시킨 코드
	int* r2 = new int[col] {6, 7, 8, 9, 10};
	int* r3 = new int[col] {11, 12, 13, 14, 15};

	int** rows = new int* [row] {r1, r2, r3}; // 포인터 배열
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			cout << rows[r][c] << " ";
		cout << endl;*/
	


	// 이중 포인터로 구현한 것
	int** matrix = new int* [row]; // 포인터 배열 선언

	// 포인터 배열 초기화
	for (int r = 0; r < row; r++)
		matrix[r] = new int[col];

	// 포인터에 값 넣기
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			matrix[r][c] = s2da[r][c];
		
	// print all elements
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			cout << matrix[r][c] << " ";
		cout << endl;
	
	// delete
	for (int r = 0; r < row; r++)
		delete[] matrix[r];
	delete[] matrix;

	

	// 이중포인터 없이 포인터로만 구현한 것
	int* mat = new int[row * col];

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			mat[c + col * r] = s2da[r][c];

	// 모든 원소확인
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			cout << mat[c + col * r] << " ";
		cout << endl;

	delete[] mat;

	return 0;
}