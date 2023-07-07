#include <iostream>

using namespace std;

class Mother
{
private:
//protected:
	int m_i;

public:
	/*Mother()
		: m_i(0)
	{}*/ // 좀 덜 세련된 해결방법

	Mother(const int& i_in)
		: m_i(i_in)
	{
		cout << "Mother constructor" << endl;
	}

	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue()
	{
		return m_i;
	}
};

class Child : public Mother // derived class : 상속받은 클래스
{							// generalized class : 일반화된 클래스(부모)
private:
	double m_d;

public: // Child의 생성자가 호출될 때, 내부적으로 Mother의 생성자도 같이 호출된다, 매우 중요한 개념
	Child(const int& i_in, const double& d_in)
	//	: m_i(i_in), m_d(d_in) 상속 받았을 때는 메모리 할당 + 생성자 호출 순서 때문에 이게 안 됨
		: Mother(i_in), m_d(d_in) // 이렇게 하면 깔끔하다
	{
		/*Mother::setValue(i_in);
		m_d = d_in;*/
	}

	void setValue(const int& i_in, const double& d_in)
	{
		Mother::setValue(i_in);
		m_d = d_in;
		//m_i = i_in; // protected를 쓰는 방법
	}

	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};

class Daughter : public Mother
{

};

class Son : public Mother
{

};

int main()
{
	Mother mother(1024);
	//mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child(1024, 128); // double인데 implicit cast가 자동으로 됐음
	/*child.Mother::setValue(1024);
	child.setValue(128);*/
	cout << child.Mother::getValue() << endl;
	cout << child.getValue() << endl;

	return 0;
}