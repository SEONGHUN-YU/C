#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template<typename T>
std::string ToString(T x)
{
	std::ostringstream osstream;
	osstream << x;
	return osstream.str();
}

template<typename T>
bool FromString(const std::string& str, T& x)
{
	std::istringstream isstream(str);
	return isstream >> x ? true : false;
}

int main()
{
	{
		//std::string my_string("my string");
		const char* my_string = "my string";
		std::cout << my_string << std::endl;

		std::string second_string(my_string, 3);
		// std::string 일 때와 const char* 일 때의
		// string 생성자의 작동이 다르다
		std::cout << second_string << std::endl;

		std::string third_string(10, 'A');
		std::cout << third_string << std::endl;

		std::vector<char> vec;
		for (auto e : "Today is a good day.")
			vec.push_back(e);
		std::string fourth_string(vec.begin(), vec.end());
		std::cout << fourth_string << std::endl;

		std::string fifth_string(vec.begin(), std::find(vec.begin(), vec.end(), 'y'));
		std::cout << fifth_string << std::endl;

		std::string my_str(std::to_string(1004));
		//my_str += std::to_string(128);
		int i = std::stoi(my_str);
		float f = std::stof(my_str);
		std::cout << my_str << std::endl;
		std::cout << i << std::endl;
		std::cout << f << std::endl;

		std::string my_str2(ToString("Hello"));
		std::cout << my_str2 << std::endl;
		double d;
		if (FromString(my_str2, d))
			std::cout << d << std::endl;
		else
			std::cout << "Cannot convert string to double" << std::endl;
	}

	return 0;
}