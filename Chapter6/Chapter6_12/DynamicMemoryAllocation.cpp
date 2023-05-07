#include <iostream>

using namespace std;

int main()
{
	// �޸� �Ҵ��� 3������ ������
	// 1. static memory allocation : ���� �޸� �Ҵ�
	// ���� ����, static ����, �� �� �����
	// ���α׷��� ���� ������ ��� �޸𸮸� ������ �ִ´�

	// 2. �ڵ� �޸� �Ҵ� : stack������ ��
	// ������ ����, ���� �迭�� ������ ���� �� ��� ������ ������
	// ���� ������� �޸𸮰� OS�� �Ҵ�(�ݳ�)�ȴ�

	// 3. dynamic memory allocation : ���� �޸� �Ҵ�

	// stack�� �޸� ũ�Ⱑ �۴�, heap�� �޸� ũ�Ⱑ ũ��
	// ���� ���� �Ҵ����� heap���� ����� �ʼ����̴�

	/*int var;
	var = 7;*/
	int* ptr = new (std::nothrow) int{ 7 }; // Ÿ�� �����ŭ, OS���� �޸𸮸� �޾ƿͼ� �� �޸� �ּҸ� �˷��ش�
	// => ���� �����ͷ� �޾ƾ� ��
	//*ptr = 7; // ���� ����� �ʱ�ȭ�� ���� ����

	/*int* ptr2 = new int(10); // �����ͷ� �޸𸮸� �Ҵ��ϸ鼭 ���ÿ� �ʱ�ȭ�� ������ �� �ִ�
	int* ptr3 = new int{ 20 }; // 2���� ���*/
	int* ptr2 = ptr;
	delete ptr; // <- ���� �ϴ� �Ǽ�
	ptr = nullptr;
	ptr2 = nullptr; // �� ���, �굵 nullptr ����� ��, �� ��Դ´� ��

	if (ptr) // ptr != nullptr �̶� �Ȱ��� �۵���
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}
	else
	{
		cout << "Could not allocate memory" << endl;
	}

	delete ptr; // OS���� �޸𸮸� �����ִ�(�ݳ�) ���
	ptr = nullptr; // ������ �����Ϳ� 0 �Ǵ� NULL �Ǵ� nullptr(��õ)�� �־��־� ���� ���ٰ� ������ش�

	// delete�� ���� �ʾƵ� �ƹ� ���� �����µ�, �� ������ OS��
	// � ���α׷��� �޸𸮸� ��ŭ ����� �ϴ� ����� ����ϰ� �ִٰ� 
	// �� ���α׷��� ����ʰ� ���ÿ� �ڵ����� �˾Ƽ� �Ⱦ�� ����
	
	// delete�� ���� ���α׷��� ����Ǳ� ����, ���� �ݳ��ϰڴٴ� �ǹ�

	cout << "After delete" << endl;
	if (ptr != nullptr) // �߿��� Ʈ��
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}

	// memory leak : �޸� ����
	/*while (1)
	{
		int* ptr = new int; // �����͸� �Ἥ ���� �Ҵ��� �� ��, ����� �� �����ϴ� �Ǽ�
		cout << ptr << endl;
		delete ptr;
	}*/

	// new�� delete�� �ƹ����� OS�� �� �� ���ľ� �ϱ� ������ stack���� ������(����)
	// stack���θ� § �ڵ尡 �ӵ��� �� �����ٴ� ���ϴ�, �׷��� �޸𸮰� ���ڶ� ��

	return 0;
}