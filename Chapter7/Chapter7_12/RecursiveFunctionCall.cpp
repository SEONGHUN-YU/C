#include <iostream>

using namespace std;

void countDown(int count)
{
	if (count < 0) return;
	cout << count << endl;
	countDown(count - 1);
}

int sumTo(int sum)
{
	if (sum <= 0)
		return 0;
	else if (sum <= 1)
		return 1;
	else
		return sumTo(sum - 1) + sum;
}

int main()
{
	//countDown(5);
	cout << sumTo(5) << endl;
	return 0;
}