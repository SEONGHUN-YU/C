#pragma once

#include <iostream>

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value);

	Calc& add(int value); // ������� ���� ���� �صδ� �� �Ϲ����ε�
	Calc& sub(int value); // � ��쿡�� ����� �׳� ���Ǻθ� ���δ� ��쵵 �ִٰ� ��
	Calc& mult(int value);
	void print();
};