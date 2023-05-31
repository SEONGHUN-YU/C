#include <iostream>
#include <string>

using namespace std;

int main()
{
	// syntax error : 문법 오류
	// semantic error : 문맥 오류(논리 오류)
	// violated assumption
	std::string hello = "Hello, my name is Jack Jack";
	cout << "Input from 0 to " << hello.size() - 1 << endl;
	while (1)
	{
		int ix;
		cin >> ix;
		if (ix >= 0 && ix <= hello.size())
		{
			cout << hello[ix] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}

	return 0;
}