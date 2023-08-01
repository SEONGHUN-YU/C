#include "Storage.h"

using namespace std;

template<typename T>
T getMax(T x, T y)
{
	return x > y ? x : y;
}

template<> // 이렇게 써두면 char 타입일 때만 특별하게 작동함
char getMax(char x, char y)
{
	cout << "Warning : comparing chars" << endl;
	return x > y ? x : y;
}

int main()
{
	cout << getMax<int>(1, 2) << endl; // 이런 식으로 instantiation 되고 있다고 생각해도 됨, 생략해도 되는 것
	cout << getMax('a', 'b') << endl;

	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print();

	return 0;
}