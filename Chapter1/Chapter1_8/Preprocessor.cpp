#include <iostream>
#include <algorithm> // max �Լ��� ���� ������

using namespace std;

// #define MY_NUMBER "hello world" // �ĺ��ڸ� ������, �ڿ� ������ ��ü�ع���
// ���������� ���� �����̴�, ��ó������ �ĺ��ڸ��� ��� �빮�ڸ� ���� ���� ����
// ��ó����� ��ũ�� ��� �θ��� ��?
#define MAX(a, b) (a > b ? a : b)
// #define MAX(a, b) (((a) > (b)) ? (a) : (b)) �̷��� �ᵵ ���� �ڵ�� ���� ������ �Ѵ�
#define LIKE_APPLE // #define�� ���� �� cpp���� �������� ȿ���� ����ȴ�

int main()
{
	cout << MAX(25, 50) << endl;
	cout << std::max(10 + 30, 20) << endl;

// ��ó����� ���� ���� ���� ó���Ѵ�
// �����ϸ�, ���������� ������������ ���� �ٸ��� �����Ѵٴ��� �ϴ� ���� ����
// conditional compilation ��� �θ���
#ifdef LIKE_APPLE
	cout << "Apple" << endl;
#endif
	// #else�� ó���ϴ� ����� ����, #ifdef - #else - #endif
#ifndef LIKE_APPLE
	cout << "Orange" << endl; // ���ǿ� ���� �ʾƼ� ��ó���⿡ ���� �帮�� �� �ڵ�
#endif

	return 0;
}