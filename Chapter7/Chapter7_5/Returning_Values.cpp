#include <iostream>
#include <array>
#include <tuple>

using namespace std;

/*int getValue(int x) // return by value
{
	int value = x * 2;
	return value;
}*/

/*int* getValue(int x) // return by address
{
	int value = x * 2;
	return &value;
}*/

int& getValue(int x) // return by reference
{
	int value = x * 2;
	return value;
}

int* allocateMemory(int size) // 뭔가, 이런 식으로 OOP에서 factory패턴 등에, 주소값 return이 쓰이는 듯 함
{
	return new int[size]; // 이런 식으로 하면 단점도 있는데, delete를 어느 시점에 해야할지 신경을 써야한다
	// 일반적으로, 이런 식으로 동적 메모리를 할당하는 방법은 프로그래머를 힘들게 만들 가능성이 있으니 피하는 것이 좋음
}

int& get(std::array<int, 100>& my_array, int index)
{
	return my_array[index];
}

struct S // struct : 사용자 정의 데이터형
{
	int a, b, c, d;
};

S getStruct() // return by struct
{
	S my_s{ 1,2,3,4 };
	return my_s;
	// 이 방식은 명확한 단점이 있는데
	// 함수 하나를 만들 때마다, 구조체를 하나씩 만들어줘야 한다
	// 옛날 lib들이 이런 식으로 많이 짜여져 있음

	// c스타일 코딩을 꼭 해야하는 상황이라면 (c++을 사용할 수 없는 상황이라던지)
	// 어쩔 수 없이, 이런 방법을 사용해야 하는 경우가 있을 수는 있음
	// 다만, 아무래도 c스타일이다보니 c++스타일보다 속도는 더 빠름
}

std::tuple<int, double> getTuple() // return by tuple
{
	int a = 10;
	double d = 3.14;
	return std::make_tuple(a, d);
}

// 값, 참조, 주소, 구조체, tuple등을 return 할 수 있다
// value, reference, address, struct, tuple, ...

// return value optimization 이라는 것도 있는데 추후에 배우게 될 것

int main()
{
	//int value = getValue(3); // 일반적인 value로 return 받을 때
	//int value = *getValue(3); // 권장하지 않음, 경우에 따라선 문제가 될 수 있음 <- 위험함 ★
	// 함수가 종료되면 사라질, 로컬변수의 주소를 역참조하는 것이기 때문 <- 이런 코딩은 가급적 안 하는 것이 좋음
	//int *value = getValue(3); // 주소를 포인터로 받음, 위에꺼보다 더 위험함 ★

	int* array = allocateMemory(1024);
	delete[] array; // new는 저기있고 delete는 여기있고 이러면 정신이 없어서 좋지 않다

	int value = getValue(5); // 이건 비교적 안전함
	cout << value << endl;
	int& value_ref = getValue(5); // 받는 쪽에서도 ref로 받아버리면, 사라질 로컬변수를 참조하는 꼴이 되어버리기 때문에
	// 문제가 생길 가능성이 높음 ★
	cout << value_ref << endl;

	std::array<int, 100> my_array; // 주소는 어딘가에 안전하게 두고
	my_array[30] = 10;
	get(my_array, 30) = 1024; // ref만 보내주고 그걸 이용해서 무언가 작업하는 형태
	// 수학 lib이나 framework들이 이런 방식으로 많이 짜여져 있는 듯
	cout << my_array[30] << endl;

	S my_s = getStruct(); // c스타일, struct로 return 받음
	cout << my_s.b << endl;

	std::tuple<int, double> my_tp = getTuple();
	cout << std::get<0>(my_tp) << endl; // a
	cout << std::get<1>(my_tp) << endl; // d

	/*auto [a, d] = getTuple(); // c++17부터 지원하는, tuple을 받는 새로운 방식
	cout << a << endl;
	cout << d << endl;*/

	return 0;
}