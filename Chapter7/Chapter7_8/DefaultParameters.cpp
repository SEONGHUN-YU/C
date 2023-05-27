#include <iostream>
#include <string>

using namespace std;

void print(int x)
{
	cout << x << endl;
}

//void print(int x, int y = 20) <- arguments로 1개만 받을 때 위에 것과 구분이 안 되게 됨
// ambiguous(모호성)이 생겨버려서 컴파일이 안 됨, 다시 말해서, default 설정은 overloading에도 영향을 준다
void print(int x, int y) // <- 이런 식으로 하면 가능
{
	cout << x << endl;
}

void test(int x = 10, int y = 20, int z = 30); // in header
// 기본값 설정은 헤더파일, 소스파일을 통틀어서 한 군데에만 해줘야 한다
// 다만, 헤더파일쪽에 default가 정의되어 있는 것이 좋고, 일반적으로 그렇게 한다고 한다

//void test(int x, int y = 20, int z) <- Error
void test(int x, int y, int z) // 가장 오른쪽에 있는 요소를 기준으로
{	// 오른쪽에서부터 왼쪽으로 default 값을 채워나갈 수 있는데
	// 왼쪽만 default를 준다던지 중간에만 default를 준다던지 하는 것은 불가능하다
	
	cout << x << " " << y << " " << z << endl;
}

/*void print(std::string str) { cout << str << endl; }
void print(char ch = ' ') { cout << ch << endl; }*/ // 응용한 것?

int main()
{
	print(1);
	test(1);

	return 0;
}