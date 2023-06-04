#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
	// access specifier : private이 기본설정으로 되어 있다
	int m_month;
	int m_day;
	int m_year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}

	void setMonth(const int& month_input)
	{
		m_month = month_input;
	}

	void setDay(const int& day_input)
	{
		m_day = day_input;
	}

	void setYear(const int& year_input) // setter
	{
		m_year = year_input;
	}

	int getMonth() // getter
	{
		return m_month;
	}

	int getDay() // 복사가 되니까 메모리적으로 안 좋다고 생각돼서 ref로 return 하려는 경우가 있는데
	{
		return m_day;
	}

	const int& getYear() // ref로 나갈 때는 바꿀 수 없게 const로
	{
		return m_year;
	}

	void copyFrom(const Date& original)
	{
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}
};

int main()
{
	Date today; //{ 8,4,2025 };
	/*today.m_month = 8;
	today.m_day = 4;
	today.m_year = 2025;*/
	today.setDate(8, 4, 2025);
	today.setMonth(10);
	cout << today.getDay() << endl;

	Date copy;
	copy.copyFrom(today);

	return 0;
}