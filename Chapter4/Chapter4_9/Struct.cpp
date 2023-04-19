#include <iostream>
#include <string>

using namespace std;

struct Person
{
	double height = 3.0;
	float weight = 200.0;
	int age = 100;
	string name = "Incredible"; // default ���� �־��� �� ����
	
	void print()
	{
		cout << height << " " << weight << " " << age << " " << name << endl;
	}
};

struct Family
{
	Person me, mom, dad;
};

Person getMe()
{
	Person me{ 2.0, 100.0, 20, "Jack" };
	return me;
}

struct Employee // 2 + (2) + 4 + 8 = 14 bytes + (2) // padding
{
	short id; // 2 bytes
	int age; // 4 bytes
	double wage; // 8 bytes, wage : �ӱ�
};

/*void printPerson(Person ps)
{
	cout << ps.height << " " << ps.weight << " " << ps.age << " " << ps.name << endl;
}*/

int main()
{
	Person me{ 2.0, 100.0, 20, "Jack" }; // �� ��, uniform initialization�� �����ϰ� ����
	me.print(); // default ������, �����ϸ鼭 �ʱ�ȭ���ִ� �� �켱 ������ �� ����
	
	Person me2(me);
	me2.print();
	
	Person me3;
	me3 = me; // �׻� ���� �ǵ��Ѵ�� �۵����� ���� �� ����, ���� ������ ���
	me3.print();

	Person me_from_func = getMe();
	me_from_func.print();

	//printPerson(me);
	
	/*me.age = 20;
	me.name = "Jack";
	me.height = 2.0;
	me.weight = 100.0;*/

	Employee emp1; // 14 bytes
	cout << sizeof(Employee) << endl; // 14 bytes�� ���;� �´µ� padding ������ 16�� ���´�

	return 0;
}