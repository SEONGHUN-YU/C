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

//auto doSomething2(std::unique_ptr<Resource> res) #●
void doSomething2(Resource* res)
{
	res->setAll(10);
	//return res; #●
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

		// early return이나 throw에도 끄덕 없음
		std::unique_ptr<Resource> res(new Resource(100000)); // unique_ptr을 사용한 것
		// 블록을 떠남과 동시에 알아서 delete를 해줌
	}

	{
		std::unique_ptr<int> upi(new int);

		//std::unique_ptr<Resource> res1(new Resource(5)); // 기본사용 방법, 포인터를 직접 넣어도 되고, 동적 할당된 instance를 직접 넣어도 된다
		auto res1 = std::make_unique<Resource>(5); // 좀 더 권장하는 방법, auto부분은 unique_ptr<Resource>가 된다
		//auto res1 = doSomething();

		// unique_ptr은 내부적으로 move semantics를 사용하기 때문에
		// 소유권이 넘어가고, copy 계열을 호출 안 하기 때문에 빠르다

		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

		//res2 = res1; // unique_ptr은 복사를 못한다 (copy semantics == value semantics를 할 수 없다는 뜻)
		res2 = std::move(res1); // 소유권을 넘겨주는 것만 가능

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

		//res1 = doSomething2(std::move(res1)); // 요즘 나오는 언어등에서는 일부러 이런 방식을 고집하기도 한다고 함 == 소유권을 줬다가 받았다가 하는 방식 : move semantics 사용
		// &를 쓰는 게 훨씬 편할테니 &를 쓰자
		doSomething2(res1.get());

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		res1->print();
	}

	{
		Resource* res = new Resource;
		std::unique_ptr<Resource> res1(res);
		//std::unique_ptr<Resource> res2(res); // 여러 군데에 소유권 주지 말자, 이러면 2번 지우게 됨
		// 나중에 문제 생김 error 유발코드
		
		//delete res; // unique_ptr을 쓰면 delete는 쓰지 말자, unique_ptr에게 delete를 맡기자
		// 나중에 문제 생김 error 유발코드
	}

	return 0;
}