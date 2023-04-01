#include <iostream>

namespace space1
{
	namespace inner
	{
		int innerFunc()
		{
			return 1024;
		}
	}

	int func(int a, int b)
	{
		return a + b;
	}
}

namespace space2
{
	int func(int a, int b)
	{
		return a * b;
	}
}

using namespace std;

int main()
{
	// namespace�� �����, �� �� ��ó�� Ǯ�������� ����ص� ���� �������
	// using namespace space1; // ���� ��Ͽ� namespace�� ������ �����ϴ� �͵� �������
	using namespace space1::inner; // �̷������� ���� �͵� ����
	cout << innerFunc() << endl;

	// cout << space1::func(3, 4) << endl;
	// cout << space2::func(3, 4) << endl;

	return 0;
}