#include <iostream>

using namespace std;

enum class Colors
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE
};

void printColorName(Colors color)
{
	switch (static_cast<int>(color))
	{
	case 0:
		cout << "Black" << endl;
		break;
	case 1:
		cout << "White" << endl;
		break;
	case 2:
		cout << "Red" << endl;
		break;
	case 3:
		cout << "Green" << endl;
		break;
	case 4:
		cout << "Blue" << endl;
		break;
	}
}

int main()
{
	printColorName(Colors::BLACK);

	int x;
	cin >> x;

	{ // ��ü�� ������� ���μ�(���� �������� �����) ������ ���� ������(1ȸ��) �������� ���� ��� #1
		int k = 0; // ����������, ������ �ٱ��� �����ϴ� ���� ���� �� ���ٰ� ��

		switch (x) // switch-case���� case�� ���� �������� ������ �����ѵ�
					// �ʱ�ȭ�� �Ұ����ϴ� -> �޸� �Ҵ��� �� �ȴٴ� �Ҹ�
		{
				int a;
			case 0:
				int y; // ������ ���⼭ �ϴ��� �ٱ��� a �ڸ����� ������ �Ͱ� �Ȱ��� �۵��Ѵ�
				a = 1;
				cout << a << endl;
				break;
			case 1:
				y = 5;
				cout << y << endl;
		}
	}

	// ������ ����� ���� �������̸� ���� ���������� ���ǵ��� �ؾߵǰ�
	// ���Ǳ� ������ �����ؼ� ����ϴ� �� ����, �� ��Ģ�� ������ ���� ������� ���δ� ��

	switch (x)
	{
		case 0: // case���� ������� ���μ�(���� �������� �����) ������ ���� ������(1ȸ��) �������� ���� ��� #2
		{
			int y = 5;
			y = y + x;
			cout << y << endl;
			break;
		}
		case 1:
		{
			int y = 5;
			y = y - x;
			cout << y << endl;
			break;
		}
		default:
			cout << "Undefined input " << x << endl;
			break; // <- ������ �������� ����� default���� break�� �ʿ������ ������ ���߰� �Ǽ��� ���̱� ����
					// ���� ���� ��쵵 ���ٰ� �Ѵ�
	}

	{
		switch (x)
		{
		case 0:
			cout << "Zero" << endl;
		case 1:
			cout << "One" << endl;
		case 2:
			cout << "Two" << endl;
			break;
		}
	}

	return 0;
}