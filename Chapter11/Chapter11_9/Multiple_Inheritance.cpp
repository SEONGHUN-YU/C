#include <iostream>

using namespace std;

class USBDevice
{
private:
	long m_id;

public:
	USBDevice(long id) : m_id(id) {}
	
	long getID() { return m_id; }

	void plugAndPlay() {}
};

class NetworkDevice
{
private:
	long m_id;

public:
	NetworkDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(long usb_id, long net_id)
		: USBDevice(usb_id), NetworkDevice(net_id)
	{}

	/*USBNetworkDevice(long id) // 이런 방식도 있긴 한데, 경우에 따라, 가능한 경우, 불가능한 경우가 있다고 함
		: USBDevice(id), NetworkDevice(id) // 그다지 자주 쓸 거 같아보이지는 않음, 참고용으로 남겨둠
	{}*/
};

int main()
{
	USBNetworkDevice my_device(3.14, 6.022);

	my_device.networking();
	my_device.plugAndPlay();

	//my_device.getID(); // 상속받은 함수명이 같아서, 모호성 때문에 문제가 생김
	my_device.USBDevice::getID(); // 이런 식으로 소속을 써주면 문제 없음
	my_device.NetworkDevice::getID();

	// 다중상속을 잘못 사용하면 여러가지 문제가 발생할 수 있는데
	// 다이아몬드 상속에서, C 클래스는 여러개의 A 클래스 사본을 가질 수 있기 때문에
	// 다이아몬드 상속 구조는 될 수 있으면 피하는 게 좋다
	// 그렇다고 해서, 모든 다이아몬드 상속이 무조건 나쁘고, 하면 안되는 것은 아니다
	// 다이아몬드 상속은 문제가 발생할 위험이 큰 구조이다, 정도로만 알고 넘어가자

	return 0;
}