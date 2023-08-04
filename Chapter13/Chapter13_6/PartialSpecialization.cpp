#include <iostream>

using namespace std;

template<class T, int size>
class StaticArray_BASE // ��� �غ�
{
private:
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[] (int index) { return m_array[index]; }

	void print() // ����Լ��� specialization �ϱⰡ ���ŷӴ�, �� ���ϰ� �����ϱ� ���� ������� ó��
	{
		for (int count = 0; count < size; ++count)
			cout << (*this)[count] << " ";
		cout << endl;
	}
};

template<class T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{
};

template<int size>
class StaticArray<char, size> : public StaticArray_BASE<char, size>
{
public:
	void print()
	{
		for (int count = 0; count < size; ++count)
			cout << (*this)[count];
		cout << endl;
	}
};

//template<typename T, int size>
//void print(StaticArray<T, size>& array)
//{
//	for (int count = 0; count < size; ++count)
//		cout << array[count] << " ";
//	cout << endl;
//}

//template<int size>
//void print(StaticArray<char, size>& array)
//{
//	for (int count = 0; count < size; ++count)
//		cout << array[count];
//	cout << endl;
//}

int main()
{
	StaticArray<int, 4> int4;
	for (int i = 0; i < 4; ++i)
		int4[i] = i + 1;
	//print(int4); ����Լ��� �ű�� ��
	int4.print();

	StaticArray<char, 14> char14;
	/*for (int i = 0; i < 14; ++i)
		char14[i] = static_cast<char>(i + (int)'a');*/
	strcpy_s(char14.getArray(), 14, "Hello, World");
	//strcpy_s((char*)&char14[0], 14 * sizeof(char), "Hello, World");
	//print(char14); ����Լ��� �ű�� ��
	char14.print();

	return 0;
}