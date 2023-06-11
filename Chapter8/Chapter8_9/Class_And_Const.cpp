#include <iostream>
#include <string>

using namespace std;

class Something
{
public:
	int m_value = 0;

	Something(const Something& st_in) // 평소에는 숨겨져 있음, 수동으로 구현가능
	{
		m_value = st_in.m_value;
		cout << "Copy Constructor" << endl;
	}

	Something()
	{
		cout << "Constructor" << endl;
	}

	void setValue(int value) { m_value = value; }
	int getValue() const { return m_value; } // instance가 const라면, 함수를 const를 붙여서 const {} 로 만들어줘야 한다
};

class Something_str
{
public:
	string m_value = "default";

	const string& getValue() const // const냐 아니냐로 overloading이 된다
	{
		cout << "const version" << endl;
		return m_value;
	}
	string& getValue()
	{
		cout << "non-const version" << endl;
		return m_value;
	}
};

void print(const Something& st)
{
	cout << &st << endl;
	cout << st.getValue() << endl; // st.m_value보다 st.getValue()가 더 깔끔함
}

int main()
{
	const Something something; // const를 선언한 instance의 멤버들은 모두 const가 적용된 것과 같다고 보면 된다
	//something.setValue(3); <- 따라서, 불가능
	cout << something.getValue() << endl;
	cout << &something << endl;
	print(something);

	Something_str something_str;
	something_str.getValue() = 10; // 값 바꿔줄 수 있음
	const Something_str something_str2;
	something_str2.getValue(); // const여서 값 못 바꿈

	return 0;
}

