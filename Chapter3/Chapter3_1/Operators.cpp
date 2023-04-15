#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << std::pow(2, 3) << endl;
	cout << -5 / 2 << endl; // c+11���� -�� ������ �����ϸ� ����� -�� ������
							// -�� ������ �����ϸ� �Ҽ��δ� ����Ǿ� �� ���� -2�� ���´�
	float ff;
	sizeof(float);
	sizeof ff; // ������ ��� () ���� ����, sizeof�� ���� �� �Լ�����, �������̱� ����

	int a = 1, b = 2;
	int c = (++a, ++b);
	cout << c << endl;

	// int x, y;
	// cin >> x >> y;
	// cout << "Values : " << x << ", " << y << endl;

	double d1(100 - 99.99);
	double d2(10 - 9.99);

	const double epsilon = 1e-10; // �� ���, 1e-16���� �ϸ� else�� ��

	if (std::abs(d1 - d2) < epsilon) cout << "Approximately equal" << endl;
	else cout << "Not equal" << endl;
	
	// short-circuit ���� ����
	
	bool r1 = true || false && false; // ����Ե� &&�� ||���� �켱������ �� ����
	bool r2 = (true || false) && false;
	bool r3 = true || (false && false);

	cout << r1 << " " << r2 << " " << r3 << endl;

	return 0;
}