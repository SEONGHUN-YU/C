#include <iostream>

using namespace std;

void printArray(const int array[], const int length)
{
	for (int i = 0; i < length; i++) cout << array[i] << " ";
	cout << endl;
}

int main()
{
	const int length = 5;
	int array[length] = { 3, 5, 2, 1, 4 };
	printArray(array, length);

	/*int temp = array[0];
	array[0] = array[1];
	array[1] = temp;*/ // std::swap(...)으로 이미 구현되어 있음

	int targetIndex, temp;
	for (int i = 0; i < length - 1; i++)
	{
		targetIndex = i;
		for (int j = i + 1; j < length; j++) 
		{
			if (array[targetIndex] > array[j]) targetIndex = j;
		}

		{ // swap(array[targetIndex], array[i]); 로 쓸 수 있음
			temp = array[targetIndex];
			array[targetIndex] = array[i];
			array[i] = temp;
		}
	}

	printArray(array, length);

	return 0;
}