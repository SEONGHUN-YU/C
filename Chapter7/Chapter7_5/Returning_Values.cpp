#include <iostream>
#include <array>
#include <tuple>

using namespace std;

/*int getValue(int x) // return by value
{
	int value = x * 2;
	return value;
}*/

/*int* getValue(int x) // return by address
{
	int value = x * 2;
	return &value;
}*/

int& getValue(int x) // return by reference
{
	int value = x * 2;
	return value;
}

int* allocateMemory(int size) // ����, �̷� ������ OOP���� factory���� �, �ּҰ� return�� ���̴� �� ��
{
	return new int[size]; // �̷� ������ �ϸ� ������ �ִµ�, delete�� ��� ������ �ؾ����� �Ű��� ����Ѵ�
	// �Ϲ�������, �̷� ������ ���� �޸𸮸� �Ҵ��ϴ� ����� ���α׷��Ӹ� ����� ���� ���ɼ��� ������ ���ϴ� ���� ����
}

int& get(std::array<int, 100>& my_array, int index)
{
	return my_array[index];
}

struct S // struct : ����� ���� ��������
{
	int a, b, c, d;
};

S getStruct() // return by struct
{
	S my_s{ 1,2,3,4 };
	return my_s;
	// �� ����� ��Ȯ�� ������ �ִµ�
	// �Լ� �ϳ��� ���� ������, ����ü�� �ϳ��� �������� �Ѵ�
	// ���� lib���� �̷� ������ ���� ¥���� ����

	// c��Ÿ�� �ڵ��� �� �ؾ��ϴ� ��Ȳ�̶�� (c++�� ����� �� ���� ��Ȳ�̶����)
	// ��¿ �� ����, �̷� ����� ����ؾ� �ϴ� ��찡 ���� ���� ����
	// �ٸ�, �ƹ����� c��Ÿ���̴ٺ��� c++��Ÿ�Ϻ��� �ӵ��� �� ����
}

std::tuple<int, double> getTuple() // return by tuple
{
	int a = 10;
	double d = 3.14;
	return std::make_tuple(a, d);
}

// ��, ����, �ּ�, ����ü, tuple���� return �� �� �ִ�
// value, reference, address, struct, tuple, ...

// return value optimization �̶�� �͵� �ִµ� ���Ŀ� ���� �� ��

int main()
{
	//int value = getValue(3); // �Ϲ����� value�� return ���� ��
	//int value = *getValue(3); // �������� ����, ��쿡 ���� ������ �� �� ���� <- ������ ��
	// �Լ��� ����Ǹ� �����, ���ú����� �ּҸ� �������ϴ� ���̱� ���� <- �̷� �ڵ��� ������ �� �ϴ� ���� ����
	//int *value = getValue(3); // �ּҸ� �����ͷ� ����, ���������� �� ������ ��

	int* array = allocateMemory(1024);
	delete[] array; // new�� �����ְ� delete�� �����ְ� �̷��� ������ ��� ���� �ʴ�

	int value = getValue(5); // �̰� ���� ������
	cout << value << endl;
	int& value_ref = getValue(5); // �޴� �ʿ����� ref�� �޾ƹ�����, ����� ���ú����� �����ϴ� ���� �Ǿ������ ������
	// ������ ���� ���ɼ��� ���� ��
	cout << value_ref << endl;

	std::array<int, 100> my_array; // �ּҴ� ��򰡿� �����ϰ� �ΰ�
	my_array[30] = 10;
	get(my_array, 30) = 1024; // ref�� �����ְ� �װ� �̿��ؼ� ���� �۾��ϴ� ����
	// ���� lib�̳� framework���� �̷� ������� ���� ¥���� �ִ� ��
	cout << my_array[30] << endl;

	S my_s = getStruct(); // c��Ÿ��, struct�� return ����
	cout << my_s.b << endl;

	std::tuple<int, double> my_tp = getTuple();
	cout << std::get<0>(my_tp) << endl; // a
	cout << std::get<1>(my_tp) << endl; // d

	/*auto [a, d] = getTuple(); // c++17���� �����ϴ�, tuple�� �޴� ���ο� ���
	cout << a << endl;
	cout << d << endl;*/

	return 0;
}