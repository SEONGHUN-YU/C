#include <iostream>
#include <vector>
#include <cstdint> // �����ʺ������� ���� ���� ������

int main()
{
	using namespace std;
	
	// int8_t i = 97; �����ʺ�����, ������ �� ������

	// typedef�� ����� aliasing ��� #1
	typedef double distance_t; // �ڵ� ���������� ����
	double my_distance;
	distance_t home2work;
	distance_t home2school;

	vector<pair<string, int>> pairlist; // <>�� bracket�̶�� �θ��� �� ��
	//typedef vector<pair<string, int>> pairlist_t;
	
	// using�� ����� aliasing ��� #2
	using pairlist_t = vector<pair<string, int>>;
	pairlist_t pairlist1;
	pairlist_t pairlist2;

	return 0;
}