#include <iostream>

using namespace std;

// void pointer, generic(포괄적인) pointer

enum Type
{
	INT,
	FLOAT,
	CHAR
};

int main()
{
	int i = 5;
	float f = 3.0f;
	char c = 'a';

	void* ptr = nullptr;

	ptr = &i;
	ptr = &f;
	//ptr = &c;

	Type type = FLOAT;
	if (type == FLOAT) cout << *static_cast<float*>(ptr) << endl;
	else if (type == INT) cout << *static_cast<int*>(ptr) << endl;
	else cout << *static_cast<char*>(ptr) << endl;

	cout << &f << " " << ptr << endl; // 주소 자체는 잘 들어가 있음
	// cout << ptr + 1 << endl; 에러, void pointer는 연산을 할 때
	// 자료형이 명시되어 있지 않아서, 몇 bytes를 더해야 하는지 알 수가 없기 때문에 막아둠
	// cout << *ptr << endl; 마찬가지로 그냥 해서는 역참조도 안 됨
	cout << *static_cast<float*>(ptr) << endl;

	int* ptr_i = &i;
	cout << ptr_i << endl;
	cout << ptr_i + 1 << endl;

	return 0;
}