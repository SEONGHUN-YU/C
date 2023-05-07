#include <iostream>

using namespace std;

const char* getName()
{
	return "Jack Jack";
}

int main()
{
	//char name[] = "haha hoho";
	//char* name = "Jack Jack"; // 실제로 값이 담길 메모리를 어디서 만들 것인가, 에 대한 아무런 정보가 없어서
								// 포인터에는 리터럴을 담을 수 없다, 포인터는 오직, 메모리의 주소를 가리키기만 할 수 있다
	const char* name = "Jack Jack"; // const를 붙여서 기호적인 상수처럼 만들면 담을 수 있게 된다
	const char* name2 = getName();
	cout << (uintptr_t)name << endl;
	cout << (uintptr_t)name2 << endl;

	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello, World!";
	
	cout << int_arr << endl;
	cout << char_arr << endl;
	cout << name << endl;
	// cout에서 문자열의 포인터가 들어오면 특별히 처리해준다

	char c = 'Q';
	cout << *&c << endl;
	// 그래서 위험성이 있다, 주소로 접근한 걸 다시 역참조해서 값으로 바꿔준 모습

	return 0;
}