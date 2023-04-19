#include <iostream>
#include <string>

using namespace std;

struct Person
{
	double height = 3.0;
	float weight = 200.0;
	int age = 100;
	string name = "Incredible"; // default 값을 넣어줄 수 있음
	
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
	double wage; // 8 bytes, wage : 임금
};

/*void printPerson(Person ps)
{
	cout << ps.height << " " << ps.weight << " " << ps.age << " " << ps.name << endl;
}*/

int main()
{
	Person me{ 2.0, 100.0, 20, "Jack" }; // 이 때, uniform initialization이 유용하게 쓰임
	me.print(); // default 값보다, 선언하면서 초기화해주는 게 우선 순위가 더 높다
	
	Person me2(me);
	me2.print();
	
	Person me3;
	me3 = me; // 항상 내가 의도한대로 작동하지 않을 수 있음, 조금 위험한 방식
	me3.print();

	Person me_from_func = getMe();
	me_from_func.print();

	//printPerson(me);
	
	/*me.age = 20;
	me.name = "Jack";
	me.height = 2.0;
	me.weight = 100.0;*/

	Employee emp1; // 14 bytes
	cout << sizeof(Employee) << endl; // 14 bytes가 나와야 맞는데 padding 때문에 16이 나온다

	return 0;
}