#include <iostream>
#include <tuple>

using namespace std;

// ref�� ���� ����, class�� ����, tuple�� ����

tuple<int, int> my_func()
{
	return tuple<int, int>(123, 456);
	//return make_tuple<int, int>(123, 456); �ε� ������
}

auto my_func2()
{
	return tuple(123, 456, 789, 10); // c++17���ʹ� tuple�� template parameter�� ������ ���� �����ϴ�
}

int main()
{
	{
		tuple<int, int> result = my_func();
		cout << get<0>(result) << " " << get<1>(result) << endl;
	}

	{
		auto [a, b, c, d] = my_func2();
		cout << a << " " << b << " " << c << " " << d << endl;
	}

	return 0;
}