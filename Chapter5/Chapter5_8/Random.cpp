#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
#include <random> // c++11부터 생김

using namespace std;

unsigned int PRNG() // Pseudo Random Number Generator
{					// Random의 매우 대략적인 로직(?)
	static unsigned int seed = 5523; // seed number
	seed = 8253729 * seed + 2396403;
	return seed % 32768;
}

// const double fraction = 1.0 / (RAND_MAX + 1.0); 전역 상수로 만들어서 쓰는 방법도 있긴 함

int getRandomNumber(int min, int max) // 특정한 정수사이의 Random Number를 발생시키는 함수
{
	// RAND_MAX : Random Number를 생성할 때, 나올 수 있는 가장 큰 숫자
	static const double fraction = 1.0 / (RAND_MAX + 1.0); // 나누기 연산은 느리기 때문에
															// 미리 나눠놓고, 곱해서 사용하는 것으로
															// 효율과 속도를 높임
	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

int main()
{
	// srand(5323); 고정된 seed <- 디버깅할 때 좋음
	srand(static_cast<unsigned int>(time(0))); // seed를 현재 시간에 맞춰서 바꿔줌 -> 무작위성을 높임
	
	// random lib에서 가져옴
	// 디바이스 -> 생성기(디바이스) -> 분포 설정, 분포 만듬 -> 분포(생성기) -> 난수 생성
	random_device rd;
	mt19937_64 mersenne(rd()); // create a mersenne twister,
	uniform_int_distribution<> dice(1, 6);
	
	for (int count = 1; count <= 20; ++count)
	{
		cout << dice(mersenne) << endl;

		// cout << getRandomNumber(5, 8) << "\t";
		// cout << rand() % 4 + 5 << "\t"; // 위의 함수와 같은 효과, 5~8의 랜덤한 숫자가 나옴
		if (count % 5 == 0) cout << endl;
	}

	return 0;
}