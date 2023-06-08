#include <iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	}

	~Simple() // 소멸자 : instance가 사라질 때 호출이 되는 함수
	{
		cout << "Destructor " << m_id << endl;
	}
};

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];
		cout << "생성" << endl;
	}

	~IntArray() // 소멸자는 parameter가 없다
	{
		if (m_arr != nullptr) delete[] m_arr;
		cout << "소멸" << endl;
	}

	int size()
	{
		return m_length;
	}
};

int main()
{
	/*//Simple s1(0); // 정적 할당
	Simple* s1 = new Simple(0); // 동적 할당
	Simple s2(1);
	delete s1;*/

	int i = 0;
	while (true)
	{
		if (i == 10) break;
		IntArray my_int_arr(10);
		i++;
	}

	return 0;
}