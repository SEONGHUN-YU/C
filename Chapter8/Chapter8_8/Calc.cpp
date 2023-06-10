#include "Calc.h"

using namespace std; // 프로그래머 성향에 따라서 이렇게 써놓는 걸 싫어하는 사람도 있다고 함

Calc::Calc(int init_value)
	: m_value(init_value)
{}

Calc& Calc::add(int value) {
	m_value += value;
	return *this;
}

Calc& Calc::sub(int value) {
	m_value -= value;
	return *this;
}

Calc& Calc::mult(int value) {
	m_value *= value;
	return *this;
}

void Calc::print() {
	cout << m_value << endl;
}
