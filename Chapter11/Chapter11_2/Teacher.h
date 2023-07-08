#pragma once

//#include <string>
#include "Person.h"

class Teacher : public Person
{
private:
	//std::string m_name; 상속 받아서 지워도 됨
	//TODO: more members like home address, salary, age, evaluation, etc...

public:
	Teacher(const std::string& name_in = "No Name")
		: Person(name_in)
	{}

	/*void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName()
	{
		return m_name;
	}*/

	void teach()
	{
		std::cout << getName() << " is teaching" << std::endl;
	}

	friend std::ostream& operator<< (std::ostream& out, const Teacher& teacher)
	{
		//out << teacher.m_name;
		out << teacher.getName();
		return out;
	}
};