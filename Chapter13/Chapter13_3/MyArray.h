#pragma once

#include <assert.h>
#include <iostream>

template<typename T, unsigned int T_SIZE> // T_SIZE�� ������ Ÿ�ӿ� ������ �Ǿ��־�� �Ѵ�

class MyArray
{
private:
	//int m_length;
	T* m_data; // T m_data[T_SIZE] �̷� �������ϸ� ���� �迭�� ��, �ٸ� ū ����� ������ �����ϴ� �������� �ϴ� �� ����
	// T_SIZE ��ü�� ������ Ÿ�ӿ� �����Ǿ�� ������
	// �� ���� �迭�� ���� �� �ִ� �� �ƴ϶�, ���� ���� ���� �迭�� ���� �� ����

public:
	MyArray()
	{
		m_data = new T[T_SIZE];
	}

	~MyArray()
	{
		delete[] m_data;
		m_data = nullptr;
	}

	T& operator[] (int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	void print() // cpp���Ϸ� �������µ�, explicit instantiation ���ֱⰡ �ָ��ϴ�, print()�� �ᱹ �ٽ� ����� ���ƿ� ���
	{
		for (int i = 0; i < T_SIZE; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}
};