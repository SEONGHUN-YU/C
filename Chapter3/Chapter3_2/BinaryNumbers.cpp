#include <iostream>

using namespace std;

int main()
{
	// c++���� ���� �����ڴ� ����, <cmath>�� pow�� ����ؾ� ��
	
	/*
		148 (decimal to binary) #1

		148 / 2 = 74 r0 (r = remainder)
		74	/ 2 = 37 r0
		37	/ 2 = 37 r1
		18	/ 2 = 9  r0
		9	/ 2 = 4  r1
		4	/ 2 = 2  r0
		2	/ 2 = 1  r0
		1	/ 2 = 0  r1
		
		�Ʒ��������� ���� ���´� 1001'0100 <- ��ȯ�Ϸ�
		--------------------------------------------------
		148 (decimal to binary) #2

		148 >= 128(2^7)		 true	= 1
		(148-128)== 20 >= 64 false  = 0
					20 >= 32 false	= 0
					20 >= 16 true	= 1
		(20-16)==	 4 >= 8  false	= 0
					 4 >= 4	 true	= 1
		(4-4)==		 0 >= 2	 false	= 0
					 0 >= 1  false	= 0

		���������� �Ʒ��� ���´� 1001'0100 <- ��ȯ�Ϸ�
	*/

	// signed vs unsigned

	return 0;
}