#include <iostream>
#include <array>
#include <functional> // c++11���� ������

using namespace std;

int func()
{
	return 5;
}

int goo()
{
	return 10;
}

bool isEven(const int& number)
{
	if (number % 2 == 0) return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 == 1) return true;
	else return false;
}

//typedef bool (*check_fcn_t)(const int&);
using check_fcn_t = bool (*)(const int&); // ���� typedef�� �Ȱ��� ������

void printNumbers(const std::array<int, 10>& my_array,
	//check_fcn_t check_fcn = isEven) // �Լ������͸� parameter�� �־��� �� �ִ�
	std::function<bool(const int&)> check_fcn) // functional�� function<>�� ����� ���, ���� �Ͱ� �Ȱ��� ������
{
	for (auto i : my_array) if (check_fcn(i)) cout << i;
	cout << endl;
}

int main()
{
	std::array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };
	std::function<bool(const int&)> fcnptr_test = isEven;
	printNumbers(my_array, fcnptr_test);
	fcnptr_test = isOdd;
	printNumbers(my_array, fcnptr_test);

	/*printNumbers(my_array); // �⺻�� �ý��� Ȱ��
	printNumbers(my_array, isOdd);*/
	
	//int(*fcnptr)(int) = func; <- parameter�� ���� ���� ���� ������ �ڷ����� �־��ش�
	int(*fcnptr)() = func;
	cout << fcnptr() << endl;
	fcnptr = goo; // parameter�� returnŸ���� ������� �Լ������͸� �� �� �ִ�
	cout << fcnptr() << endl;
	//cout << func << endl; // �Լ��� �����ʹ�, �Լ��� �޸𸮿� ���´�

	return 0;
}