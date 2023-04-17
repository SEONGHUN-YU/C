#include <iostream>

int main()
{
	using namespace std;
	
	// c++11부터 추가된 기능이라고 함 -> enum class
	enum class Color
	{
		RED,
		BLUE
	};

	enum class Fruit
	{
		BANANA,
		APPLE
	};

	Color color1 = Color::BLUE;
	Color color2 = Color::BLUE;

	if (color1 == color2) cout << "Same color " << endl;

	// Fruit fruit = Fruit::BANANA;

	// if (static_cast<int>(color) == static_cast<int>(fruit)) cout << "Color is fruit ? " << endl;
	// 강제로 비교한 것, 원래는 캐스팅하지 않아도 같다고 나왔음

	return 0;
}