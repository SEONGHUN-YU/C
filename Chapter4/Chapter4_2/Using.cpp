#include <iostream>

// 변수나 함수의 이름이 같을 때 컴파일러가 무엇을 써야하는지 모르겠다고
// 불만을 토로하게 되는데 이것을 Ambiguity(모호성)이라고 한다
// 이 때, 모호성을 해결해주는 것이 using이라는 키워드다

namespace a
{
	int my_var(10);
	int my_a(123);
	int count = 123123;
}

namespace b
{
	int my_var(20);
	int my_b(456);
}

int main()
{
	using namespace std;
	/*using std::cout; // 이렇게 부분적으로만 가져올 수도 있긴 하다
	using std::endl;*/

	// using namespace를 특정 헤더에서 전역 범위에 넣어버리면
	// 그 헤더를 include하는 모든 cpp파일에 영향을 주게 되어버린다
	// => 무시무시한 오류가 발생할 수 있다
	// 따라서 unsing namespace는 헤더보다는, 가급적이면 cpp파일에 넣는 것이 좋다
	// 전역에서 사용하는 것만큼은 피하는 것이 좋다

	{
		using namespace a;
		cout << my_var << endl;
		// cout << count << endl; // std에도 count가 있기 때문에 에러
	}

	{
		using namespace b;
		cout << my_var << endl;
	}

	cout << a::my_var << endl;
	cout << b::my_var << endl;

	// cout << my_a << endl;
	// cout << my_b << endl;

	cout << "Hello " << endl;

	return 0;
}