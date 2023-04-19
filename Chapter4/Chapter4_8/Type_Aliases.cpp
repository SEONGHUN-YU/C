#include <iostream>
#include <vector>
#include <cstdint> // 고정너비정수를 쓰기 위해 가져옴

int main()
{
	using namespace std;
	
	// int8_t i = 97; 고정너비정수, 복습할 겸 가져옴

	// typedef를 사용한 aliasing 방법 #1
	typedef double distance_t; // 코드 유지보수에 좋음
	double my_distance;
	distance_t home2work;
	distance_t home2school;

	vector<pair<string, int>> pairlist; // <>를 bracket이라고 부르는 듯 함
	//typedef vector<pair<string, int>> pairlist_t;
	
	// using을 사용한 aliasing 방법 #2
	using pairlist_t = vector<pair<string, int>>;
	pairlist_t pairlist1;
	pairlist_t pairlist2;

	return 0;
}