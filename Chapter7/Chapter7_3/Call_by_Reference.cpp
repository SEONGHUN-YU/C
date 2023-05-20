#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void addOne(int& y) // ������ ���� ������ ���簡 �̷������ ����
{					// ������ ���� ����Ǿ� �������� �ʴ� �� -> �ӵ� ���
	y = y + 1;
	cout << y << " " << &y << endl;
}

void getSincos(const double& degrees, double& sin_out, double& cos_out)
{	// c++������ �Է��� �տ�, ���� return(���)���� ���� �͵��� �ڿ� �δ� �� �Ϲ����̴�
	// �Է����θ� ���� �͵��� const�� ���Ƶд�
	static const double pi = 3.141592 / 180.0;
	const double radians = degrees * pi;
	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

/*void foo(const int& x) // const�� ���̸� ref���� ���� ���� ���� ���ͷ��� ���� �� �ְ� �ȴ�
{
	cout << x << endl;
}*/

typedef int* pint;

//void foo(int*& ptr)
void foo(pint& ptr) // (int*) &ptr ��� �ؼ��ϸ� ����
{
	cout << ptr << " " << &ptr << endl;
}

//void printElement(int(&arr)[4])
void printElement(const vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int x = 5;
	cout << x << " " << &x << endl;
	addOne(x);
	cout << x << " " << &x << endl;

	double sin(0.0);
	double cos(0.0);
	getSincos(30.0, sin, cos);
	cout << sin << " " << cos << endl;

	int xx = 5;
	//int* ptr = &xx;
	pint ptr = &xx; // typedef�� ����� ����
	cout << ptr << " " << &ptr << endl;
	foo(ptr);

	//int arr[]{ 1,2,3,4 }; ���� �迭
	vector<int> arr{ 1,2,3,4 }; // ���� �迭�� ��ȭ��
	printElement(arr);

	return 0;
}