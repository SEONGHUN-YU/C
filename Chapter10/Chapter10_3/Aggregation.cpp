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

	Student* ptr_std1 = new Student("Jack Jack", 0); // �ٸ� �������� �����͸� ����Ѵٸ�
	Student* ptr_std2 = new Student("Dash", 1); // ���� �Ҵ����� �����ϴ� ����� �ִ�
	Student* ptr_std3 = new Student("Violet", 2);
	Teacher* ptr_teacher1 = new Teacher("Prof. Hong");
	Teacher* ptr_teacher2 = new Teacher("Prof. Good");

	// �׻� �̷� ������ �����͸� �̿��ؼ� © �� �ִ� ���� �ƴѵ�
	// �л�ó���� ���� �̷��� © ���� ����
	// �� ���� �޸𸮰� �и��Ǿ� �ֱ� ������ �� ��ǻ��, �� ��ǻ��, �ּҸ� �������� �� �ۿ� ����
	// �� ������ �ذ��Ϸ���, ��ũ�γ�����(����ȭ)��Ű�� �۾��� �ʿ��ϴ�

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