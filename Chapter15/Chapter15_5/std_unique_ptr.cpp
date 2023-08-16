#include <memory>
#include "Resource.h"

using namespace std;

auto doSomething()
{
	/*auto res1 = std::make_unique<Resource>(5);
	return res1;*/

	/*return std::unique_ptr<Resource>(new Resource(5));*/

	return std::make_unique<Resource>(5);
}

//auto doSomething2(std::unique_ptr<Resource> res) #��
void doSomething2(Resource* res)
{
	res->setAll(10);
	//return res; #��
}

/*void doSomething2(std::unique_ptr<Resource>& res)
{
	res->setAll(10);
}*/

int main()
{
	{
		//Resource* res = new Resource(100000);
		
		// early return or throw
		
		//delete res;

		// early return�̳� throw���� ���� ����
		std::unique_ptr<Resource> res(new Resource(100000)); // unique_ptr�� ����� ��
		// ����� ������ ���ÿ� �˾Ƽ� delete�� ����
	}

	{
		std::unique_ptr<int> upi(new int);

		//std::unique_ptr<Resource> res1(new Resource(5)); // �⺻��� ���, �����͸� ���� �־ �ǰ�, ���� �Ҵ�� instance�� ���� �־ �ȴ�
		auto res1 = std::make_unique<Resource>(5); // �� �� �����ϴ� ���, auto�κ��� unique_ptr<Resource>�� �ȴ�
		//auto res1 = doSomething();

		// unique_ptr�� ���������� move semantics�� ����ϱ� ������
		// �������� �Ѿ��, copy �迭�� ȣ�� �� �ϱ� ������ ������

		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

		//res2 = res1; // unique_ptr�� ���縦 ���Ѵ� (copy semantics == value semantics�� �� �� ���ٴ� ��)
		res2 = std::move(res1); // �������� �Ѱ��ִ� �͸� ����

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

		if (res1 != nullptr) res1->print();
		if (res2 != nullptr) res2->print(); // (*res2).print();
	}

	{
		auto res1 = std::make_unique<Resource>(5);
		res1->setAll(1);
		res1->print();

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		//res1 = doSomething2(std::move(res1)); // ���� ������ ������� �Ϻη� �̷� ����� �����ϱ⵵ �Ѵٰ� �� == �������� ��ٰ� �޾Ҵٰ� �ϴ� ��� : move semantics ���
		// &�� ���� �� �ξ� �����״� &�� ����
		doSomething2(res1.get());

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		res1->print();
	}

	{
		Resource* res = new Resource;
		std::unique_ptr<Resource> res1(res);
		//std::unique_ptr<Resource> res2(res); // ���� ������ ������ ���� ����, �̷��� 2�� ����� ��
		// ���߿� ���� ���� error �����ڵ�
		
		//delete res; // unique_ptr�� ���� delete�� ���� ����, unique_ptr���� delete�� �ñ���
		// ���߿� ���� ���� error �����ڵ�
	}

	return 0;
}