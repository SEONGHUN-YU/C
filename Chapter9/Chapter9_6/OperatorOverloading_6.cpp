#include <iostream>
#include <cassert>

using namespace std;

class IntList
{
private:
	int m_list[10]{ 0,1,2,3,4,5,6,7,8,9 };

public:
	int& operator[] (const int index) // subscript operator : 첨자 연산자
	{
		assert(index >= 0); // [] 연산자를 오버로딩하는 경우는, 자주 사용하려고 만드는 경우가 많아서
		assert(index < 10); // if문 쓰면 느려지니까 assert로 디버깅만 확실히 잡는 쪽으로 구현
		return m_list[index];
	}

	const int& operator[] (const int index) const
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}

	/*void setItem(int index, int value) { m_list[index] = value; }
	int getItem(int index) { return m_list[index]; }
	int* getList() { return m_list; }*/
};

int main()
{
	const IntList my_list;
	// my_list[3] = 10;
	cout << my_list[3] << endl;
	
	/*IntList* list = new IntList; // 포인터로 구현할 때, 주의할 점
	list[3] = 10; // Not OK : 의도하지 않은 일이 일어남
	(*list)[3] = 10;*/ // OK : 역참조 먼저하고 접근

	/*IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;
	my_list.getList()[3] = 10;
	cout << my_list.getList()[3] << endl;*/
	
	return 0;
}