#pragma once

#include <iostream>
#include <string>

// 헤더에서는 using namespace std; 를 안 쓰는 게 좋기 때문에 일부러 안 쓰고 있음

class Person
{
private:
	std::string m_name;

public:
	/*Person()
		: m_name("No Name")
	{}*/

	Person(const std::string& name_in = "No Name")
		: m_name(name_in)
	{}

	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName() const // 자식에서 오버로딩 같은 거 할 때 const로 쓸 거면 여기도 const 붙여줘야 함, 매우 중요
	{
		return m_name;
	}

	void doNothing() const
	{
		std::cout << m_name << " is doing nothing" << std::endl;
	}
};