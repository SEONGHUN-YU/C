#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void addOne(int& y) // 참조에 의한 전달은 복사가 이루어지지 않음
{					// 변수가 새로 선언되어 생성되지 않는 것 -> 속도 향상
	y = y + 1;
	cout << y << " " << &y << endl;
}

void getSincos(const double& degrees, double& sin_out, double& cos_out)
{	// c++에서는 입력은 앞에, 간접 return(출력)으로 나갈 것들은 뒤에 두는 게 일반적이다
	// 입력으로만 쓰일 것들은 const로 막아둔다
	static const double pi = 3.141592 / 180.0;
	const double radians = degrees * pi;
	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

/*void foo(const int& x) // const를 붙이면 ref더라도 변수 생성 없이 리터럴을 받을 수 있게 된다
{
	cout << x << endl;
}*/

typedef int* pint;

//void foo(int*& ptr)
void foo(pint& ptr) // (int*) &ptr 라고 해석하면 편함
{
	cout << ptr << " " << &ptr << endl;
}

//void printElement(int(&arr)[4])
void printElement(const vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int x = 5;
	cout << x << " " << &x << endl;
	addOne(x);
	cout << x << " " << &x << endl;

	double sin(0.0);
	double cos(0.0);
	getSincos(30.0, sin, cos);
	cout << sin << " " << cos << endl;

	int xx = 5;
	//int* ptr = &xx;
	pint ptr = &xx; // typedef를 사용한 예시
	cout << ptr << " " << &ptr << endl;
	foo(ptr);

	//int arr[]{ 1,2,3,4 }; 정적 배열
	vector<int> arr{ 1,2,3,4 }; // 동적 배열의 강화판
	printElement(arr);

	return 0;
}