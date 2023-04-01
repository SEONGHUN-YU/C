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
	// namespace를 썼더라도, 안 쓴 것처럼 풀네임으로 사용해도 전혀 상관없고
	// using namespace space1; // 같은 블록에 namespace를 여러개 선언하는 것도 상관없다
	using namespace space1::inner; // 이런식으로 쓰는 것도 가능
	cout << innerFunc() << endl;

	// cout << space1::func(3, 4) << endl;
	// cout << space2::func(3, 4) << endl;

	return 0;
}