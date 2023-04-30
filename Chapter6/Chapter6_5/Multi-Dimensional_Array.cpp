#include <iostream>

using namespace std;

int main()
{
	// 동적 메모리 할당을 배우면, 다차원 배열을 더 자유롭게 다룰 수 있게된다고 함

	const int num_rows = 3;
	const int num_columns = 5;

	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_columns; col++)
		{
			cout << '[' << row << ']' << '[' << col << ']' << '\t';
		}
		cout << endl;
	}
	cout << endl;

	// 2차원 배열을 선언과 동시에 초기화할 때 row는 생략가능하다, 명시되어 있기 때문
	// [r][c] = { 0 }; 으로 모두 0으로 채운 배열을 생성할 수도 있다
	int array[num_rows][num_columns] = // <- row-major방식, <-> column-major방식도 존재한다 함
	{									// 실제로 메모리 구조 안에서는 결국은 일렬로 늘어선 방식임
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15}
	};
	
	for (int row = 0; row < num_rows; row++)
	{
		for (int col = 0; col < num_columns; col++)
		{
			cout << (long long)&array[row][col] << '\t';
		}
		cout << endl;
	}
	
	return 0;
}