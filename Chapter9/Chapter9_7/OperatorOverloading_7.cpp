#include <iostream>

using namespace std;

class Accumulator
{
private:
	int m_counter = 0;

public:
	int operator() (int i) { return m_counter += i; } // parenthesis : 괄호 연산자 (), function call operator
	// function-object (Functor) : 함수객체
};

int main()
{
	Accumulator acc;
	cout << acc(10) << endl;
	cout << acc(20) << endl;

	return 0;
}