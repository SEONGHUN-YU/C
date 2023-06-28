#include <iostream>
#include <cassert>

using namespace std;

class MyString
{
public:
	char* m_data = nullptr;
	int m_length = 0;

public:
	MyString(const char* source = "")
	{
		assert(source);

		m_length = std::strlen(source) + 1; // null character 추가를 위해 1칸 추가
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	//MyString(const MyString& source) = delete; 복사 생성자를 막아버리는 방법도 있음, 다만 차선책으로 봐야 함

	MyString(const MyString& source) // 복사 생성자
	{
		cout << "Copy constructor " << endl;

		m_length = source.m_length;
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];
			for (int i = 0; i < m_length; ++i) // 깊은 복사하는 중
				m_data[i] = source.m_data[i];
		}
		else m_data = nullptr; // 멤버변수 기본값으로 넣어놔서, 이 부분은 없어도 크게 문제가 되지 않지만 넣어둠
	}

	MyString& operator= (const MyString& source) // 할당 연산자 오버로딩
	{
		// copy constructor는 밑의 코드가 default임 <- shallow copy라서 문제가 생길 수 있음
		/*this->m_data = source.m_data;
		this->m_length = source.m_length;*/

		cout << "Assignment operator " << endl;

		if (this == &source) // prevent self-assignment
			return *this;
		delete[] m_data; // 복사 생성자의 경우는 새로 생성하는 거니까 문제가 안 생기는데
		// 할당 연산자의 경우 원래 주소를 가지고 있을 수 있기 때문에
		// 문제가 생길 수 있어서 일단 지우고, 주소를 다시 잡아줌

		m_length = source.m_length;
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];
			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else m_data = nullptr;
	}

	~MyString()
	{
		delete[] m_data;
	}
	
	char* getString() { return m_data; }
	int getLength() { return m_length; }
};

int main()
{
	MyString hello("Hello");
	cout << (int*)hello.m_data << endl;
	cout << hello.getString() << endl;

	{
		MyString copy = hello; // 얕은 복사
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
	} // 이 시점에서 복사본이 원본의 heap 메모리를 지워버림, 블록(스코프)을 떠나면서 소멸자가 발동하기 때문

	cout << hello.getString() << endl; // 지워진 메모리에 접근하려 하니, 쓰레기값이 나옴

	MyString str = hello; // 선언과 동시에 초기화하며 복사할 때는, 복사 생성자 발동
	MyString str2; // 기본 생성자 발동
	str2 = hello; // 할당 연산자 발동

	return 0;
}