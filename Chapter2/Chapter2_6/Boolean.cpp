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

	if (true) // 1�ٸ� �����ϰ� ���� ����, ��� �ʿ����, 2�� �̻��� ��� �ݵ�� ��� �ʿ�
	{
		cout << "This is true" << endl;
		cout << "True second line" << endl;
	}
	else
	{
		cout << "This is false" << endl;
	}

	if (-1) // 0�� �ƴϸ� �������� True�� ���´�
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