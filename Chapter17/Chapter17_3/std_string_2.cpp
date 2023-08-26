#include <iostream>
#include <string>

using namespace std;

int main()
{
	string my_str("01234567");
	my_str.reserve(1000); // capacity를 reserve에 최대한 가깝게 늘려줌(일반적으론 약간 더)

	cout << my_str.length() << endl;
	cout << my_str.size() << endl;
	cout << my_str.capacity() << endl; // 이거는 컴파일러나 OS에 따라 다를 수 있음
	// 될 수 있으면 memory re-allocation을 피하기 위해 capacity를 여유롭게 늘려둠
	cout << my_str.max_size() << endl;
	
	cout << boolalpha;
	cout << my_str.empty() << endl; // ""도 비어있다고 나옴, null character를 보관하지 않음

	return 0;
}