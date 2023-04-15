#include <iostream>

using namespace std;

int main()
{
	// c++에는 제곱 연산자는 없다, <cmath>의 pow를 사용해야 함
	
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
		
		아래에서부터 위로 적는다 1001'0100 <- 변환완료
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

		위에서부터 아래로 적는다 1001'0100 <- 변환완료
	*/

	// signed vs unsigned

	return 0;
}