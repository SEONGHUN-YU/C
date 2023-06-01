#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	// command line arguments : 명령줄 인수
	for (int i = 0; i < argc; ++i)
	{
		std::string argv_single = argv[i];
		if (i == 1)
		{
			int input_number = std::stoi(argv_single);
			std::cout << input_number + 1 << std::endl;
		}
		std::cout << argv_single << std::endl;
	}

	return 0;
}