#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception
{
public:
	const char* what() const noexcept override // noexcept는 c++11이상에서 적어도 이 함수 내에서는, 예외를 던지지(만들지) 않겠다는 의미
	{
		return "Custom exception";
	}
};

int main()
{
	try
	{
		/*std::string s;
		s.resize(-1);*/

		//throw std::runtime_error("Bad thing happened");
		throw CustomException();
	}
	/*catch (std::length_error& exception)
	{
		std::cout << "Length_Error" << std::endl;
		std::cerr << exception.what() << std::endl;
	}*/
	catch (std::exception& exception)
	{
		std::cout << typeid(exception).name() << std::endl;
		std::cerr << exception.what() << std::endl; // 가장 중요한 함수, overriding할 경우를 대비해 기억해놓자
	}

	return 0;
}