#include <iostream>
#include <typeinfo>

/*int computeDamage(int weapon_id)
{
	if (weapon_id == 0) return 1; // sword
	
	if (weapon_id == 1) return 2; // hammer
	
	// ...
}*/

enum Color // user-defined data types
{
	COLOR_BLACK = -3,
	COLOR_RED,
	COLOR_BLUE = 5,
	COLOR_GREEN = 5,
	COLOR_SKYBLUE,
	// BLUE <- 다른 블록이지만, 전역처럼 작동함, 중복되면 안 됨
};

enum Feeling // enum은 보통 헤더에 넣어서 forward declaration 하는 방식을 많이 쓴다고 한다
{
	HAPPY,
	JOY,
	TIRED,
	BLUE
};

int main()
{
	using namespace std;

	Color paint = COLOR_BLACK;
	Color house(COLOR_BLUE);
	Color apple{ COLOR_RED };

	Color my_color = COLOR_RED;

	cout << my_color << " " << COLOR_RED << endl;

	if (COLOR_BLUE == COLOR_GREEN) cout << "Equal" << endl;

	int color_id = COLOR_RED;
	cout << color_id << endl;
	
	// Color my_color2 = 3; <- 안 됨
	Color my_color2 = static_cast<Color>(3); // <- 굳이 할당하고 싶다면, 캐스팅 해줘야 함

	int in_number;
	cin >> in_number;

	// 직접적으로 cin은 안 되지만, detour(우회)해서 할당하는 것은 가능하다
	if (in_number == static_cast<Color>(0)) my_color = static_cast<Color>(0);
	// ...

	return 0;
}