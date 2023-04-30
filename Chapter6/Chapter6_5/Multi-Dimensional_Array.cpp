#include <iostream>

using namespace std;

int main()
{
	// ���� �޸� �Ҵ��� ����, ������ �迭�� �� �����Ӱ� �ٷ� �� �ְԵȴٰ� ��

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

	// 2���� �迭�� ����� ���ÿ� �ʱ�ȭ�� �� row�� ���������ϴ�, ��õǾ� �ֱ� ����
	// [r][c] = { 0 }; ���� ��� 0���� ä�� �迭�� ������ ���� �ִ�
	int array[num_rows][num_columns] = // <- row-major���, <-> column-major��ĵ� �����Ѵ� ��
	{									// ������ �޸� ���� �ȿ����� �ᱹ�� �Ϸķ� �þ �����
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