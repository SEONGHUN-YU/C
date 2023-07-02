#pragma once

#include <vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
	std::string m_name;

	// 주석 처리된 것들은 composition으로 짠 것

	/*Teacher teacher;
	std::vector<Student> students;*/

	Teacher *teacher;
	std::vector<Student*> students;

public:
	Lecture(const std::string& name_in)
		: m_name(name_in)
	{}

	~Lecture()
	{
		// do NOT delete teacher
		// do NOT delete students
	}

	/*void assignTeacher(const Teacher& const teacher_input)
	{
		teacher = teacher_input;
	}*/

	void assignTeacher(Teacher* const teacher_input)
		// 주소를 넘겨주는 거라서 const Teacher에서 const는 빼야 한다
	{
		teacher = teacher_input;
	}

	//void registerStudent(const Student& const student_input)
	//{
	//	students.push_back(student_input);
	//	// &student_input != &students[0]
	//	// 복사해서 넣었기 때문에 주소가 다르다
	//}

	void registerStudent(Student* const student_input)
	{
		students.push_back(student_input);
	}

	void study()
	{
		std::cout << m_name << " Study" << std::endl;
		
		//for (auto& element : students) //Note: 'auto element' doesn't work
		//	// &없이 auto만 쓰면, 값이 업데이트가 안 됨
		//	element.setIntel(element.getIntel() + 1);

		for (auto element : students) //Note: 'auto element' works
		// 이 때는 auto도 auto&도 상관없다
			(*element).setIntel((*element).getIntel() + 1);
			//element->setIntel(element->getIntel() + 1); 로 쓸 수도 있다
	}

	friend std::ostream& operator<< (std::ostream& out, const Lecture& lecture)
	{
		out << "Lecture name : " << lecture.m_name << std::endl;
		
		/*out << lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << element << std::endl;*/

		out << *lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << *element << std::endl;
		return out;
	}
};