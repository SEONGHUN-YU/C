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

	/*USBNetworkDevice(long id) // �̷� ��ĵ� �ֱ� �ѵ�, ��쿡 ����, ������ ���, �Ұ����� ��찡 �ִٰ� ��
		: USBDevice(id), NetworkDevice(id) // �״��� ���� �� �� ���ƺ������� ����, ��������� ���ܵ�
	{}*/
};

int main()
{
	USBNetworkDevice my_device(3.14, 6.022);

	my_device.networking();
	my_device.plugAndPlay();

	//my_device.getID(); // ��ӹ��� �Լ����� ���Ƽ�, ��ȣ�� ������ ������ ����
	my_device.USBDevice::getID(); // �̷� ������ �Ҽ��� ���ָ� ���� ����
	my_device.NetworkDevice::getID();

	// ���߻���� �߸� ����ϸ� �������� ������ �߻��� �� �ִµ�
	// ���̾Ƹ�� ��ӿ���, C Ŭ������ �������� A Ŭ���� �纻�� ���� �� �ֱ� ������
	// ���̾Ƹ�� ��� ������ �� �� ������ ���ϴ� �� ����
	// �׷��ٰ� �ؼ�, ��� ���̾Ƹ�� ����� ������ ���ڰ�, �ϸ� �ȵǴ� ���� �ƴϴ�
	// ���̾Ƹ�� ����� ������ �߻��� ������ ū �����̴�, �����θ� �˰� �Ѿ��

	return 0;
}