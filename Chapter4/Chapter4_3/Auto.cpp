#include <iostream>

// template ?

auto add(int x, int y) // auto�� parameter���� �� �� ����
{
	return x + y; // c++17���� �������� return���� ���ÿ� ��ȯ�� �� �ִ� ����� �����ϴ� ��?
}

auto add(double x, double y) -> double // Ʈ���ϸ�, ���븦 ����� �� ?
{										// Python�� type hint�� ����� �� ����
	return x + y;
}

int main()
{
	using namespace std;

	auto a = 123;
	auto d = 123.0;
	auto c = 1 + 2.0; // �Ǽ�
	auto result = add(1, 2);

	return 0;
}