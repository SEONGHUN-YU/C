#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
#include <random> // c++11���� ����

using namespace std;

unsigned int PRNG() // Pseudo Random Number Generator
{					// Random�� �ſ� �뷫���� ����(?)
	static unsigned int seed = 5523; // seed number
	seed = 8253729 * seed + 2396403;
	return seed % 32768;
}

// const double fraction = 1.0 / (RAND_MAX + 1.0); ���� ����� ���� ���� ����� �ֱ� ��

int getRandomNumber(int min, int max) // Ư���� ���������� Random Number�� �߻���Ű�� �Լ�
{
	// RAND_MAX : Random Number�� ������ ��, ���� �� �ִ� ���� ū ����
	static const double fraction = 1.0 / (RAND_MAX + 1.0); // ������ ������ ������ ������
															// �̸� ��������, ���ؼ� ����ϴ� ������
															// ȿ���� �ӵ��� ����
	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

int main()
{
	// srand(5323); ������ seed <- ������� �� ����
	srand(static_cast<unsigned int>(time(0))); // seed�� ���� �ð��� ���缭 �ٲ��� -> ���������� ����
	
	// random lib���� ������
	// ����̽� -> ������(����̽�) -> ���� ����, ���� ���� -> ����(������) -> ���� ����
	random_device rd;
	mt19937_64 mersenne(rd()); // create a mersenne twister,
	uniform_int_distribution<> dice(1, 6);
	
	for (int count = 1; count <= 20; ++count)
	{
		cout << dice(mersenne) << endl;

		// cout << getRandomNumber(5, 8) << "\t";
		// cout << rand() % 4 + 5 << "\t"; // ���� �Լ��� ���� ȿ��, 5~8�� ������ ���ڰ� ����
		if (count % 5 == 0) cout << endl;
	}

	return 0;
}