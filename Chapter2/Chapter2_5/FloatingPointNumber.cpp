#include <iostream>
#include <iomanip> // 입출력을 조작해주는 lib
#include <limits>
#include <cmath> // isnan()을 사용하기 위함

using namespace std;

int main()
{
	float f(3.141592f); // 3.14 = 31.4 * 0.1 ?
	double d(3.141592);
	long double ld(3.141592);

	cout << 3.14 << endl;
	cout << 31.4e-1 << endl;
	cout << 31.4e-2 << endl;
	cout << 31.4e1 << endl;
	cout << 31.4e2 << endl;

	cout << numeric_limits<float>::max() << endl;
	cout << numeric_limits<float>::min() << endl;
	cout << numeric_limits<float>::lowest() << endl;
	cout << numeric_limits<double>::max() << endl;
	cout << numeric_limits<double>::min() << endl;
	cout << numeric_limits<double>::lowest() << endl;
	cout << numeric_limits<long double>::max() << endl;
	cout << numeric_limits<long double>::min() << endl;
	cout << numeric_limits<long double>::lowest() << endl;

	float k(123456789.0f); // 10 significant digits <- 유효숫자 10개
	double r(0.1);

	double v(1.0);
	double v2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

	double zero = 0.0;
	double posinf = 5.0 / zero;
	double neginf = -5.0 / zero;
	double nan = zero / zero;

	cout << posinf << " " << std::isinf(posinf) << endl;
	cout << neginf << " " << std::isinf(neginf) << endl;
	cout << posinf << " " << std::isnan(posinf) << endl;
	cout << neginf << " " << std::isnan(neginf) << endl;
	cout << nan << " " << std::isnan(nan) << endl;
	
	cout << r << endl;
	cout << std::setprecision(17) << endl; // 앞으로 출력될 것들에 대한 설정을 바꿔줌
	cout << r << endl;
	cout << k << endl;
	cout << 1.0 / 3.0 << endl;
	cout << v << endl;
	cout << v2 << endl;

	return 0;
}