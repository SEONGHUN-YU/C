#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

template void MyArray<char>::print(); // explicit instantiation
// 이렇게 써주면 문제가 해결된다
// print라는 함수를 char타입에 대해서 instantiation할 거니까, 빌드를 이렇게 해라라고 컴파일러에게 알려주는 것

// 다른방법도 있음, class 자체를 explicit instantiation 하는 방법
template class MyArray<char>;
template class MyArray<double>; // 여러개 써줘도 됨, 써준 것들만 적용됨