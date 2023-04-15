#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	/*
		bool item0_flag = false;
		bool item1_flag = false;
		bool item2_flag = false;
		bool item3_flag = false;
		...
	*/

	const unsigned char opt0 = 1 << 0;
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;

	cout << bitset<8>(opt0) << endl;
	cout << bitset<8>(opt1) << endl;
	cout << bitset<8>(opt2) << endl;
	cout << bitset<8>(opt3) << endl;

	unsigned char items_flag = 0;
	cout << "No item " << bitset<8>(items_flag) << endl;

	// item0 on
	items_flag |= opt0;
	cout << "Item0 obtained " << bitset<8>(items_flag) << endl;
	
	// item3 on
	items_flag |= opt3;
	cout << "Item3 obtained " << bitset<8>(items_flag) << endl;

	// item3 lost
	items_flag &= ~opt3;
	cout << "Item3 lost " << bitset<8>(items_flag) << endl;

	// has item1 check
	if (items_flag & opt1) cout << "Has item1" << endl;
	else cout << "Not have item1" << endl;

	// has item0 check
	if (items_flag & opt0) cout << "Has item0" << endl;
	else cout << "Not have item0" << endl;

	// obtain item2,3 동시에
	items_flag |= (opt2 | opt3);
	cout << bitset<8>(opt2 | opt3) << endl;
	cout << "Item2,3 obtained " << bitset<8>(items_flag) << endl;

	if ((items_flag & opt2) && !(items_flag & opt1))
	{
		items_flag ^= opt2;
		items_flag ^= opt1;
	}
	cout << bitset<8>(items_flag) << endl;


	// bit mask 예시
	const unsigned int red_mask = 0xFF0000;
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	cout << bitset<32>(red_mask) << endl;
	cout << bitset<32>(green_mask) << endl;
	cout << bitset<32>(blue_mask) << endl;

	unsigned int pixel_color = 0xDAA520; // (r, g, b) 값을 구하려는 대상

	cout << bitset<32>(pixel_color) << endl;

	unsigned char red = (pixel_color & red_mask) >> 16;
	unsigned char green = (pixel_color & green_mask) >> 8; // 8칸을 오른쪽으로 밀어서 자릿수를 1바이트와 같게 해줌
	unsigned char blue = pixel_color & blue_mask; // 8비트까지밖에 못 받음

	cout << "red " << bitset<8>(red) << " " << int(red) << endl;
	cout << "green " << bitset<8>(green) << " " << int(green) << endl;
	cout << "blue " << bitset<8>(blue) << " " << int(blue) << endl;

	return 0;
}