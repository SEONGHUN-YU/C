#include <iostream>

using namespace std;

int getInt()
{
	while (true)
	{
		cout << "Enter an integer number : ";
		int x;
		cin >> x;
		if (cin.fail()) // bool로 return됨
		{
			cin.clear();
			cin.ignore(32767, '\n'); // 띄어쓰기된, 뒤에 입력값들 다 무시
			cout << "Invalid number, please try again" << endl;
		}
		else
		{
			cin.ignore(32767, '\n');
			return x;
		}
	}
}

char getOperator()
{
	while (true)
	{
		cout << "Enter an operator (+, -) : "; // TODO: more operators *, / etc
		char op;
		cin >> op;
		cin.ignore(32767, '\n');
		if (op == '+' || op == '-') return op;
		else cout << "Invalid operator, please try again" << endl;
	}
}

void printResult(int x, char op, int y)
{
	if (op == '+') cout << x + y << endl;
	else if (op == '-') cout << x - y << endl;
	else cout << "Invalid operator" << endl;
}

int main()
{
	int x = getInt();
	char op = getOperator();
	int y = getInt();

	printResult(x, op, y);

	return 0;
}