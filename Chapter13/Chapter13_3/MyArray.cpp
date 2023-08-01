#include "MyArray.h"

// explicit instantiation
//template class MyArray<char, 1>; // 1, 2, 3 ... 이런 식으로 모든 숫자를 다 써줄 수가 없으니
//template class MyArray<double>; // 자료형이 아닌 녀석이 template의 parameter로 들어왔을 때,
								// 즉, non-type parameter일 경우는 
								// 함수를 cpp파일로 빼지 않고 전부 헤더에 집어넣는 것이 나음				

//template void MyArray<char>::print();
//template void MyArray<double>::print();