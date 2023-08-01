//#include "Storage.h"
//
//template<>
//void Storage<double>::print()
//{
//	std::cout << "Double Type ";
//	std::cout << std::scientific << m_value << '\n';
//}

// 이거 막힌듯... 안 된다
// 이렇게 쓰지마라, 그냥 헤더에 다 몰아넣어라
// 이 방식으로는 specialization이 안 됨, LNK2005, LNK1169 에러가 남
// include에서 에러가 나는데 도무지 영문을 모르겠음
// 아마 컴파일러 차이라는 것 같은데, 그냥 헤더온리 방식으로 할 것
// 강의에서도 애초에 헤더에 집어넣으라고 했음
// 참고용으로 남겨둠