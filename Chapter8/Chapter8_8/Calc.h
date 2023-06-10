#pragma once

#include <iostream>

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value);

	Calc& add(int value); // 헤더에는 전방 선언만 해두는 게 일반적인데
	Calc& sub(int value); // 어떤 경우에는 헤더에 그냥 정의부를 냅두는 경우도 있다고 함
	Calc& mult(int value);
	void print();
};