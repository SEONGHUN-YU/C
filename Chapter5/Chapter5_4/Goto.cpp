#include <iostream>
#include <cmath> // sqrt()�� ����ϱ� ���� ������
				// �������Ʈ
using namespace std;

int main()
{
	double x;

tryAgain: // label

	cout << "Enter a non-negative number" << endl;
	cin >> x;

	if (x < 0) goto tryAgain;
	
	cout << sqrt(x) << endl;

	// goto skip; <- goto�� �� �ڸ����� �������

	int k = 5; // <- ������� ����

skip: // <- �ٷ� �� ��ġ�� �Ѿ�͹�����

	k += 3; // <- �ʱ�ȭ���� ���� ���¿��� �����Ϸ��� �ϱ� ������ ������ ����

	return 0;
}