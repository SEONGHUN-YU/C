//#include "Storage.h"
//
//template<>
//void Storage<double>::print()
//{
//	std::cout << "Double Type ";
//	std::cout << std::scientific << m_value << '\n';
//}

// �̰� ������... �� �ȴ�
// �̷��� ��������, �׳� ����� �� ���Ƴ־��
// �� ������δ� specialization�� �� ��, LNK2005, LNK1169 ������ ��
// include���� ������ ���µ� ������ ������ �𸣰���
// �Ƹ� �����Ϸ� ���̶�� �� ������, �׳� ����¸� ������� �� ��
// ���ǿ����� ���ʿ� ����� ���������� ����
// ���������� ���ܵ�