#include <iostream>
#include <tuple>

using namespace std;

// ref로 간접 리턴, class로 리턴, tuple로 리턴

tuple<int, int> my_func()
{
	return tuple<int, int>(123, 456);
	//return make_tuple<int, int>(123, 456); 로도 가능함
}

auto my_func2()
{
	return tuple(123, 456, 789, 10); // c++17부터는 tuple의 template parameter가 완전히 생략 가능하다
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