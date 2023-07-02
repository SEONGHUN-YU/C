#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

using namespace std;

int main()
{
	/*Student std1("Jack Jack", 0);
	Student std2("Dash", 1);
	Student std3("Violet", 2);
	Teacher teacher1("Prof. Hong");
	Teacher teacher2("Prof. Good");*/

	Student* ptr_std1 = new Student("Jack Jack", 0); // 다른 곳에서도 포인터를 써야한다면
	Student* ptr_std2 = new Student("Dash", 1); // 동적 할당으로 구현하는 방법도 있다
	Student* ptr_std3 = new Student("Violet", 2);
	Teacher* ptr_teacher1 = new Teacher("Prof. Hong");
	Teacher* ptr_teacher2 = new Teacher("Prof. Good");

	// 항상 이런 식으로 포인터를 이용해서 짤 수 있는 것은 아닌데
	// 분산처리할 때는 이렇게 짤 수가 없다
	// 그 때는 메모리가 분리되어 있기 때문에 이 컴퓨터, 저 컴퓨터, 주소를 나눠가질 수 밖에 없고
	// 그 문제를 해결하려면, 싱크로나이즈(동기화)시키는 작업이 필요하다

	// Composition Relationship -> Aggregation Relationship
	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(ptr_teacher1);
	lec1.registerStudent(ptr_std1);
	lec1.registerStudent(ptr_std2);
	lec1.registerStudent(ptr_std3);

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(ptr_teacher2);
	lec2.registerStudent(ptr_std1);

	//TODO: implement Aggregation Relationship

	//test
	{
		cout << lec1 << endl;
		cout << lec2 << endl;

		// event
		lec2.study();

		cout << lec1 << endl;
		cout << lec2 << endl;
	}

	//TODO: class HobbyClub

	//TODO: delete memory (if necessary)
	delete ptr_std1, ptr_std2, ptr_std3;
	delete ptr_teacher1, ptr_teacher2;

	return 0;
}