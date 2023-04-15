#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << std::pow(2, 3) << endl;
	cout << -5 / 2 << endl; // c+11부터 -를 나머지 연산하면 결과가 -로 나오고
							// -를 나머지 연산하면 소수부는 절삭되어 저 값은 -2가 나온다
	float ff;
	sizeof(float);
	sizeof ff; // 변수일 경우 () 생략 가능, sizeof는 생긴 건 함수지만, 연산자이기 때문

	int a = 1, b = 2;
	int c = (++a, ++b);
	cout << c << endl;

	// int x, y;
	// cin >> x >> y;
	// cout << "Values : " << x << ", " << y << endl;

	double d1(100 - 99.99);
	double d2(10 - 9.99);

	const double epsilon = 1e-10; // 이 경우, 1e-16으로 하면 else로 감

	if (std::abs(d1 - d2) < epsilon) cout << "Approximately equal" << endl;
	else cout << "Not equal" << endl;
	
	// short-circuit 잊지 말고
	
	bool r1 = true || false && false; // 놀랍게도 &&가 ||보다 우선순위가 더 높다
	bool r2 = (true || false) && false;
	bool r3 = true || (false && false);

	cout << r1 << " " << r2 << " " << r3 << endl;

	return 0;
}