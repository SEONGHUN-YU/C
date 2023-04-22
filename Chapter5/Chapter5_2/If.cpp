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

	// if문에서 한 줄만 실행할 때는 블록이 없어도 에러가 나지 않는데
	// implicit block이라고 부른다
	// condition은 0이 아니면 모두 true가 나온다
	if (x > 10) cout << x << " is greater than 10" << endl;
	else cout << x << " is not greater than 10" << endl;

	if (1)
		; // null statement, 아무것도 안 하고 싶을 때 씀

	if (x = 0) // 이런 식으로 하면 할당이 되어버린다
		cout << x << endl;
	cout << x << endl;

	return 0;
}