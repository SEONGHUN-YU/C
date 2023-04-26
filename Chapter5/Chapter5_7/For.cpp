#include <iostream>

int pow(int base, int exponent)
{
	int result = 1;

	for (int count = 0; count < exponent; ++count)
	{
		result *= base;
	}

	return result;
}

int main()
{
	using namespace std;

	int count = 0;
	for (; count < 10; ++count)
	{
		cout << count << endl;
	}
	cout << count << endl;

	// for (;; ++count) <- infinite loop
	{
		cout << count << endl;
	}

	cout << pow(2, 4) << endl;

	for (int count = 9; count >= 0; count -= 2)
	{
		cout << count << endl;
	}

	int i = 0, j = 0;
	for (; (i + j) < 10; ++i, j += 2)
	{
		cout << i << " " << j << endl;
	}

	for (j = 0; j < 9; ++j)
	{
		for (i = 0; i < 9; ++i)
		{
			cout << i << " " << j << endl;
		}
	}

	// for (unsigned int i = 9; i >= 0; --i) cout << i << endl; <- 좋지 않은 사용 예시
	// infinite loop의 가능성 때문에 unsigned int는 좋지 않음

	return 0;
}