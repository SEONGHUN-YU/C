#include <iostream>

using namespace std;

int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	int x;
	cin >> x;

	// if������ �� �ٸ� ������ ���� ����� ��� ������ ���� �ʴµ�
	// implicit block�̶�� �θ���
	// condition�� 0�� �ƴϸ� ��� true�� ���´�
	if (x > 10) cout << x << " is greater than 10" << endl;
	else cout << x << " is not greater than 10" << endl;

	if (1)
		; // null statement, �ƹ��͵� �� �ϰ� ���� �� ��

	if (x = 0) // �̷� ������ �ϸ� �Ҵ��� �Ǿ������
		cout << x << endl;
	cout << x << endl;

	return 0;
}