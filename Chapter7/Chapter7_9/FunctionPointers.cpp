#include <iostream>
#include <array>
#include <functional> // c++11부터 지원함

using namespace std;

int func()
{
	return 5;
}

int goo()
{
	return 10;
}

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

//typedef bool (*check_fcn_t)(const int&);
using check_fcn_t = bool (*)(const int&); // 위의 typedef랑 똑같이 동작함

void printNumbers(const std::array<int, 10>& my_array,
	//check_fcn_t check_fcn = isEven) // 함수포인터를 parameter에 넣어줄 수 있다
	std::function<bool(const int&)> check_fcn) // functional의 function<>을 사용한 모습, 위의 것과 똑같이 동작함
{
	for (auto i : my_array) if (check_fcn(i)) cout << i;
	cout << endl;
}

int main()
{
	std::array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };
	std::function<bool(const int&)> fcnptr_test = isEven;
	printNumbers(my_array, fcnptr_test);
	fcnptr_test = isOdd;
	printNumbers(my_array, fcnptr_test);

	/*printNumbers(my_array); // 기본값 시스템 활용
	printNumbers(my_array, isOdd);*/
	
	//int(*fcnptr)(int) = func; <- parameter가 있을 때는 저런 식으로 자료형을 넣어준다
	int(*fcnptr)() = func;
	cout << fcnptr() << endl;
	fcnptr = goo; // parameter와 return타입을 맞춰줘야 함수포인터를 쓸 수 있다
	cout << fcnptr() << endl;
	//cout << func << endl; // 함수도 포인터다, 함수도 메모리에 들어온다

	return 0;
}