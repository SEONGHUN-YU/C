// #include <iostream> Monster.h 를 include 해서 필요 없어짐
#include "Monster.h"

using namespace std;

int main()
{
	Monster mon1("Samson", Position2D(0, 0));
	
	cout << mon1 << endl; // endl;은 main에서만 쓰는 게 일반적

	Monster mon2("Parsival", Position2D(0, 0));

	//while (1) // game loop
	{
		// event
		mon1.moveTo(Position2D(1, 1));
		cout << mon1 << endl;
	}

	return 0;
}