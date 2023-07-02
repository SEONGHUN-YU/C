#pragma once

// #include <iostream> Position2D를 include 하면 필요 없어짐
#include <string>
#include "Position2D.h"

class Monster
{
private:
	std::string m_name;
	Position2D m_location; // composition : monster가 position을 사용하는 관계
	// sub class

	//int m_x; // location
	//int m_y; Position2D.h 에서 만들어서 정리해줬기 때문에 필요없어지고, Position2D로 교체

public:
	Monster(const std::string& name_in, const Position2D& pos_in)
		: m_name(name_in), m_location(pos_in)
	{}

	void moveTo(const Position2D& pos_target)
	{
		m_location.set(pos_target);
		/*m_x = x_target;
		m_y = y_target;*/
	}

	friend std::ostream& operator<< (std::ostream& out, const Monster& monster)
	{
		out << monster.m_name << " " << monster.m_location; // << std::endl;
		return out;
	}
};