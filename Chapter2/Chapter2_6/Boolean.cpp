#include <iostream>

using namespace std;

bool isEqual(int a, int b)
{
	bool result = (a == b);
	return result;
}

int main()
{
	bool b1 = true;
	bool b2(false);
	bool b3{ true };

	cout << std::boolalpha;
	cout << isEqual(1, 1) << endl;
	cout << !isEqual(0, 3) << endl;

	if (true) // 1줄만 실행하고 싶을 때는, 블록 필요없음, 2줄 이상인 경우 반드시 블록 필요
	{
		cout << "This is true" << endl;
		cout << "True second line" << endl;
	}
	else
	{
		cout << "This is false" << endl;
	}

	if (-1) // 0이 아니면 음수여도 True가 나온다
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	
	bool k;
	cin >> k;
	cout << "Your input : " << k << endl;

	return 0;
}