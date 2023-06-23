#include <iostream>
#include <cassert>

using namespace std;

class IntList
{
private:
	int m_list[10]{ 0,1,2,3,4,5,6,7,8,9 };

public:
	int& operator[] (const int index) // subscript operator : ÷�� ������
	{
		assert(index >= 0); // [] �����ڸ� �����ε��ϴ� ����, ���� ����Ϸ��� ����� ��찡 ���Ƽ�
		assert(index < 10); // if�� ���� �������ϱ� assert�� ����븸 Ȯ���� ��� ������ ����
		return m_list[index];
	}

	const int& operator[] (const int index) const
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}

	/*void setItem(int index, int value) { m_list[index] = value; }
	int getItem(int index) { return m_list[index]; }
	int* getList() { return m_list; }*/
};

int main()
{
	const IntList my_list;
	// my_list[3] = 10;
	cout << my_list[3] << endl;
	
	/*IntList* list = new IntList; // �����ͷ� ������ ��, ������ ��
	list[3] = 10; // Not OK : �ǵ����� ���� ���� �Ͼ
	(*list)[3] = 10;*/ // OK : ������ �����ϰ� ����

	/*IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;
	my_list.getList()[3] = 10;
	cout << my_list.getList()[3] << endl;*/
	
	return 0;
}