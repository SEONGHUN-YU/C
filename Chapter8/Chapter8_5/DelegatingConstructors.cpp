#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	int m_id;
	string m_name;

public:
	Student(const string& name_in)
		// : m_id(0), m_name(name_in) // 매우 비추천하는 방식
		: Student(0, name_in) // 위임 생성자 : 생성자가 다른 생성자를 사용하는 것
		// c++11부터 지원함
	{
	}

	Student(const int& id_in, const string& name_in)
		: m_id(id_in), m_name(name_in)
		// OOP 설계를 할 때, 어떠한 기능을 하는 코드는 한 곳에서만 나와야 한다
		// 한 곳에만 만들어두면, 수정할 때도 편하고, 디버깅할 때도 편해진다
	{
	}

	void print()
	{
		cout << m_id << " " << m_name << endl;
	}

	/*Student(const string& name_in) // 옛날 방식, 참고용
	{
		init(0, name_in);
	}
	Student(const int& id_in, const string& name_in)
	{
		init(id_in, name_in);
	}
	void init(const int& id_in, const string& name_in) // 만능 생성자
	{
		m_id = id_in;
		m_name = name_in;
	}*/
};

int main()
{
	Student st1(0, "Jack Jack");
	st1.print();

	Student st2("Dash");
	st2.print();

	return 0;
}