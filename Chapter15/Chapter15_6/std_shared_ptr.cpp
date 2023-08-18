#include "Resource.h"

void doSomething(std::unique_ptr<Resource> res)
{
}

int main()
{
	//doSomething(std::unique_ptr<Resource>(new Resource(100000))); 이렇게 new 하면서 집어넣는 건 좋지 않은 방식, 컴파일러마다 다를 순 있지만 지양하는 게 좋음
	doSomething(std::make_unique<Resource>(100000)); // 이 방식이 더 안전하고 좋다

	//Resource* res = new Resource(3); // unique나 shared나 둘 다 이런 식으로 만들어서 넣는 건 잘 안 함
	//res->setAll(1);

	{
		//std::shared_ptr<Resource> ptr1(res);

		auto ptr1 = std::make_shared<Resource>(3); // 직접적으로 초기화하는 방식이 더 안전하고 선호되는 방식
		ptr1->setAll(1);

		ptr1->print();

		{
			//std::shared_ptr<Resource> ptr2(ptr1); // 다단으로 간접적으로 받을 것
			//std::shared_ptr<Resource> ptr2(res); // 이런 식으로 직접 받으면 문제가 생김
			auto ptr2 = ptr1;

			ptr2->setAll(3);
			ptr2->print();

			std::cout << "Going out of the block" << std::endl;
		}

		ptr1->print(); // 직접 받았을 때 ptr1이 참조하는 res이 지워져버리기 때문에 실행이 안 됨

		std::cout << "Going out of the outer block" << std::endl;
		// shared_ptr을 쓰면 어딘가에서는 반드시 지워주기 때문에
		// new 하고 delete를 깜빡해서 생기는 memory leak에서 보다 자유롭다
	}

	return 0;
}