#include <iostream>

using namespace std;

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in)
		: m_b(m_b_in)
	{
	}
};

class Something
{
private:
	int m_i = 123; // non-static 멤버들은 초기화 시켜줄 수 있음
	double m_d;
	char m_c;
	int m_arr[5]; // c++11부터 배열도 초기화 가능
	B m_b;

public:
	Something()
		: m_i(1), m_d(3.14), m_c{ 'a' }, // member initializer list : 멤버 초기화 리스트
		m_arr{ 1,2,3,4,5 }, m_b(m_i - 1) // ()대신 {}도 됨
		// 멤버변수 초기화와, 멤버 초기화 리스트가 동시에 존재할 때는
		// 멤버 초기화 리스트가 우선 적용됨
		// 그 후에 생성자 내에서 다시 할당을 시킬 경우 최종적으로 생성자 내에서 사용된 값이 적용됨
	{
		m_i *= 1;
		m_d *= 3.0;
		m_c += 3; // 초기화 시키는 것이 아니기 때문에 이런 게 가능
	}

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& i : m_arr)
			cout << i << " ";
		cout << endl;
	}
};

int main()
{
	Something som;
	som.print();

	return 0;
}