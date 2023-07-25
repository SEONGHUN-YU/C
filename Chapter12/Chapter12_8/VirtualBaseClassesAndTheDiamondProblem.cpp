#include <iostream>

using namespace std;

class PoweredDevice
{
public:
	int m_i;

	PoweredDevice(int power)
		: m_i(power)
	{
		cout << "PoweredDevice : " << m_i << '\n';
	}
};

class Scanner : virtual public PoweredDevice // 다이아몬드 상속문제를 해결하기 위해 virtual을 넣어줌
			// virtual을 붙이면 가상 기본클래스라고 부르는 듯
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner : " << scanner << '\n';
	}
};

class Printer : virtual public PoweredDevice // 마찬가지
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		cout << "Printer : " << printer << '\n';
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)
		// virtual로 상속시키고, PoweredDevice의 생성자 추가해줌, 안 해주면 에러남
	{}
};

int main()
{
	Copier cop(1, 2, 3);

	cout << &cop.Scanner::PoweredDevice::m_i << endl;
	cout << &cop.Printer::PoweredDevice::m_i << endl;

	return 0;
}