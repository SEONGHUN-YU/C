#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

template void MyArray<char>::print(); // explicit instantiation
// �̷��� ���ָ� ������ �ذ�ȴ�
// print��� �Լ��� charŸ�Կ� ���ؼ� instantiation�� �Ŵϱ�, ���带 �̷��� �ض��� �����Ϸ����� �˷��ִ� ��

// �ٸ������ ����, class ��ü�� explicit instantiation �ϴ� ���
template class MyArray<char>;
template class MyArray<double>; // ������ ���൵ ��, ���� �͵鸸 �����