#pragma once

//#include <iostream>
//#include <string>
#include "Person.h"

class Student : public Person
{
private:
	//std::string m_name;
	int m_intel; // intelligence;

	//TODO: add more members like address, phone, favorite food, habits, ...

public:
	Student(const std::string& name_in = "No Name", const int& intel_in = 0)
		//: m_name(name_in), m_intel(intel_in)
		: Person(name_in), m_intel(intel_in)
	{}

	/*void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName()
	{
		return m_name;
	}*/

	void setIntel(const int& intel_in)
	{
		m_intel = intel_in;
	}

	int getIntel()
	{
		return m_intel;
	}
	
	void study()
	{
		std::cout << getName() << " is studying" << std::endl;
	}

	friend std::ostream& operator<< (std::ostream& out, const Student& student)
	{
		out << student.getName() << " " << student.m_intel;
		return out;
	}
};