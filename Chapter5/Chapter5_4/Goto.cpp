#include <iostream>
#include <cmath> // sqrt()를 사용하기 위해 가져옴
				// 스퀘어루트
using namespace std;

int main()
{
	double x;

tryAgain: // label

	cout << "Enter a non-negative number" << endl;
	cin >> x;

	if (x < 0) goto tryAgain;
	
	cout << sqrt(x) << endl;

	// goto skip; <- goto를 이 자리에서 써버리면

	int k = 5; // <- 실행되지 않음

skip: // <- 바로 이 위치로 넘어와버리고

	k += 3; // <- 초기화되지 않은 상태에서 연산하려고 하기 때문에 에러가 난다

	return 0;
}