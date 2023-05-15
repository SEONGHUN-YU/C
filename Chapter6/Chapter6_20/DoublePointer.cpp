#include <iostream>

using namespace std;

int main()
{
	// ���������� �⺻ ����
	int* ptr = nullptr;
	int** ptrptr = nullptr;

	int value = 5;
	ptr = &value;
	ptrptr = &ptr;

	cout << ptr << " " << *ptr << " " << &ptr << endl;
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
	cout << **ptrptr << endl;

	// ���� �Ҵ����� ������ �迭 �����
	// ���������͸� ���� ���, �� ���� ��� 2���� �ִ�
	const int row = 3;
	const int col = 5;

	const int s2da[row][col] =
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15}
	};

	/*int* r1 = new int[col] {1, 2, 3, 4, 5}; // for�� ���� �ʱ�ȭ ��Ų �ڵ�
	int* r2 = new int[col] {6, 7, 8, 9, 10};
	int* r3 = new int[col] {11, 12, 13, 14, 15};

	int** rows = new int* [row] {r1, r2, r3}; // ������ �迭
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			cout << rows[r][c] << " ";
		cout << endl;*/
	


	// ���� �����ͷ� ������ ��
	int** matrix = new int* [row]; // ������ �迭 ����

	// ������ �迭 �ʱ�ȭ
	for (int r = 0; r < row; r++)
		matrix[r] = new int[col];

	// �����Ϳ� �� �ֱ�
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

	

	// ���������� ���� �����ͷθ� ������ ��
	int* mat = new int[row * col];

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			mat[c + col * r] = s2da[r][c];

	// ��� ����Ȯ��
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			cout << mat[c + col * r] << " ";
		cout << endl;

	delete[] mat;

	return 0;
}