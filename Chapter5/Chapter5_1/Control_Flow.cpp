#include <iostream>
#include <cstdlib> // exit()이 있음

int main()
{
	using namespace std;
	// for문은 sequential flow이다

	cout << "I love you " << endl;

	exit(0); // return 대신 exit()을 넣을 수도 있음, return보다 긴급하게 끝내는 느낌
			// exit()은 디버깅할 때 많이 쓰게 된다고 함
	// ...

	cout << "I love you too" << endl;

	return 0;
}