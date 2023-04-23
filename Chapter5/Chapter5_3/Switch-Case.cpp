#include <iostream>

using namespace std;

enum class Colors
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE
};

void printColorName(Colors color)
{
	switch (static_cast<int>(color))
	{
	case 0:
		cout << "Black" << endl;
		break;
	case 1:
		cout << "White" << endl;
		break;
	case 2:
		cout << "Red" << endl;
		break;
	case 3:
		cout << "Green" << endl;
		break;
	case 4:
		cout << "Blue" << endl;
		break;
	}
}

int main()
{
	printColorName(Colors::BLACK);

	int x;
	cin >> x;

	{ // 전체를 블록으로 감싸서(로컬 영역으로 만들고) 변수를 쓰고 버리는(1회용) 느낌으로 쓰는 방식 #1
		int k = 0; // 개인차지만, 변수를 바깥에 선언하는 것이 나은 것 같다고 함

		switch (x) // switch-case문은 case로 들어가기 전까지는 선언은 가능한데
					// 초기화가 불가능하다 -> 메모리 할당이 안 된다는 소리
		{
				int a;
			case 0:
				int y; // 선언을 여기서 하더라도 바깥의 a 자리에서 선언한 것과 똑같이 작동한다
				a = 1;
				cout << a << endl;
				break;
			case 1:
				y = 5;
				cout << y << endl;
		}
	}

	// 변수를 사용할 때는 가급적이면 적은 범위에서만 사용되도록 해야되고
	// 사용되기 직전에 정의해서 사용하는 게 좋다, 는 원칙을 따르기 위해 블록으로 감싸는 것

	switch (x)
	{
		case 0: // case마다 블록으로 감싸서(로컬 영역으로 만들고) 변수를 쓰고 버리는(1회용) 느낌으로 쓰는 방식 #2
		{
			int y = 5;
			y = y + x;
			cout << y << endl;
			break;
		}
		case 1:
		{
			int y = 5;
			y = y - x;
			cout << y << endl;
			break;
		}
		default:
			cout << "Undefined input " << x << endl;
			break; // <- 어차피 마지막에 실행될 default여서 break는 필요없지만 형식을 맞추고 실수를 줄이기 위해
					// 굳이 쓰는 경우도 많다고 한다
	}

	{
		switch (x)
		{
		case 0:
			cout << "Zero" << endl;
		case 1:
			cout << "One" << endl;
		case 2:
			cout << "Two" << endl;
			break;
		}
	}

	return 0;
}