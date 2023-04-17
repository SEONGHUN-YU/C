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
	// BLUE <- �ٸ� ���������, ����ó�� �۵���, �ߺ��Ǹ� �� ��
};

enum Feeling // enum�� ���� ����� �־ forward declaration �ϴ� ����� ���� ���ٰ� �Ѵ�
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
	
	// Color my_color2 = 3; <- �� ��
	Color my_color2 = static_cast<Color>(3); // <- ���� �Ҵ��ϰ� �ʹٸ�, ĳ���� ����� ��

	int in_number;
	cin >> in_number;

	// ���������� cin�� �� ������, detour(��ȸ)�ؼ� �Ҵ��ϴ� ���� �����ϴ�
	if (in_number == static_cast<Color>(0)) my_color = static_cast<Color>(0);
	// ...

	return 0;
}