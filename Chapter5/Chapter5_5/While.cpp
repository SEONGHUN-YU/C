#include <iostream>

using namespace std;

int main()
{
	int checker = 0;
	while (1)
	{
		cout << checker++ << endl;
		if (checker == 10) break;
	}
	
	int count = 1;
	while (count < 100)
	{
		if (count % 5 == 0) cout << "Hello " << count << endl;
		count++;
	}

	int outer_count = 1;
	while (outer_count <= 5)
	{
		int inner_count = 1;
		while (inner_count <= outer_count)
		{
			cout << inner_count++ << " ";
		}
		cout << endl;
		++outer_count;
	}

	/*unsigned int count = 10; // unsigned를 감소하는 counter로 사용하게 되면 위험하다
	while (count >= 0) // -1로 가지 못해서 infinite loop
	{
		if (count == 0) cout << "Zero" << endl;
		else cout << count << " " << endl;
		count--;
	}*/
	
	return 0;
}