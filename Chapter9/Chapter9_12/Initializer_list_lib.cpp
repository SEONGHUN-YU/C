#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(unsigned length)
		: m_length(length)
	{
		m_data = new int[length]; // 중복되는 기능은 가급적 쪼개서
		// 한 곳에서만 구현되도록 만드는 습관을 들이는 게 좋다
	}

	IntArray(const std::initializer_list<int>& list) // 생성자 오버로딩
		: IntArray(list.size())
	{
		int count = 0;
		for (auto& element : list)
		{
			m_data[count++] = element;
		}

		/*for (unsigned count = 0; count < list.size(); ++count)
			m_data[count] = list[count];*/ // error, initializer list는 []를 지원하지 않음
		// 그래서 이런 방식으로, 깊은 복사 불가능
	}

	~IntArray()
	{
		delete[] this->m_data;
	}

	// TODO: overload operator=
	// 생성자 오버로딩을 할 때는, 할당 연산자 오버로딩도 같이 해주는 게 좋다

	friend std::ostream& operator<< (std::ostream& out, IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << " ";
		out << endl;
		return out;
	}
};

int main()
{
	int my_arr1[5] = { 1,2,3,4,5 }; // { } 이 부분을 initializer list 라고 부름
	int* my_arr2 = new int[5] {1, 2, 3, 4, 5};

	auto il = { 10,20,30 };

	IntArray int_array{ 1,2,3,4,5 };
	cout << int_array << endl;

	return 0;
}