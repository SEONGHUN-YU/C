#include <iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		this->setID(id); // '->' 멤버 셀렉션 오퍼레이터
		// this->가 숨어있는 것
		//(*this).setID(id); 이렇게도 가능은 한데, 굳이 이렇게까지 쓰지는 않는다
		cout << this << endl; // instance 자신의 주소
	}
	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		: m_value(init_value)
	{}
	Calc& add(int value) { m_value += value; return *this; }
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }
	void print() { cout << m_value << endl; }
};

int main()
{
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);
	cout << &s1 << " " << &s2 << endl;
	//Simple::setID(&s2, 4); <- 틀린 문법임, 개념상으론 내부적으로 이렇게 되어 있음, 참고용
	// 보이지 않는 포인터가 내부적으로 들어간다고 보면 된다

	Calc cal(10);
	/*Calc& temp1 = cal.add(10);
	Calc& temp2 = temp1.sub(1);
	Calc& temp3 = temp2.mult(2);
	temp3.print();*/
	cal.add(10).sub(1).mult(2).print(); // 위에 것처럼 작동함
	/*cal.add(10);
	cal.sub(1);
	cal.mult(2);
	cal.print();*/

	return 0;
}