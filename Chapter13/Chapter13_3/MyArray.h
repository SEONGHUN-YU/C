#pragma once

#include <assert.h>
#include <iostream>

template<typename T, unsigned int T_SIZE> // T_SIZE는 컴파일 타임에 결정이 되어있어야 한다

class MyArray
{
private:
	//int m_length;
	T* m_data; // T m_data[T_SIZE] 이런 식으로하면 정적 배열이 됨, 다만 큰 사이즈가 들어오면 난감하니 동적으로 하는 게 낫다
	// T_SIZE 자체는 컴파일 타임에 결정되어야 하지만
	// 꼭 정적 배열만 만들 수 있는 게 아니라, 위와 같이 동적 배열도 만들 수 있음

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

	void print() // cpp파일로 빼놨었는데, explicit instantiation 해주기가 애매하니, print()가 결국 다시 헤더로 돌아온 모습
	{
		for (int i = 0; i < T_SIZE; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}
};