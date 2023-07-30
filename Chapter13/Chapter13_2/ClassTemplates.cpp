#include "MyArray.h"
//#include "MyArray.cpp" // 이렇게 해결하는 건, 나중에 프로젝트가 커지면, 걷잡을 수 없는 문제가 생기니
						// 절대로 이런 식으로 하지말 것

int main()
{
	MyArray<char> my_array(10); // class옆에 argument로 들어갈 타입을 넣어줘야 template을 쓸 수 있다

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 'a';

	my_array.print();

	return 0;
}