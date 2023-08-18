#include "Resource.h"

void doSomething(std::unique_ptr<Resource> res)
{
}

int main()
{
	//doSomething(std::unique_ptr<Resource>(new Resource(100000))); �̷��� new �ϸ鼭 ����ִ� �� ���� ���� ���, �����Ϸ����� �ٸ� �� ������ �����ϴ� �� ����
	doSomething(std::make_unique<Resource>(100000)); // �� ����� �� �����ϰ� ����

	//Resource* res = new Resource(3); // unique�� shared�� �� �� �̷� ������ ���� �ִ� �� �� �� ��
	//res->setAll(1);

	{
		//std::shared_ptr<Resource> ptr1(res);

		auto ptr1 = std::make_shared<Resource>(3); // ���������� �ʱ�ȭ�ϴ� ����� �� �����ϰ� ��ȣ�Ǵ� ���
		ptr1->setAll(1);

		ptr1->print();

		{
			//std::shared_ptr<Resource> ptr2(ptr1); // �ٴ����� ���������� ���� ��
			//std::shared_ptr<Resource> ptr2(res); // �̷� ������ ���� ������ ������ ����
			auto ptr2 = ptr1;

			ptr2->setAll(3);
			ptr2->print();

			std::cout << "Going out of the block" << std::endl;
		}

		ptr1->print(); // ���� �޾��� �� ptr1�� �����ϴ� res�� ������������ ������ ������ �� ��

		std::cout << "Going out of the outer block" << std::endl;
		// shared_ptr�� ���� ��򰡿����� �ݵ�� �����ֱ� ������
		// new �ϰ� delete�� �����ؼ� ����� memory leak���� ���� �����Ӵ�
	}

	return 0;
}