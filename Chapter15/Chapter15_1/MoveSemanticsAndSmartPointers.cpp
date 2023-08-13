#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

// RAII : Resource Acquisition is initialization
// new를 사용한 곳에서 delete을 해야한다는 개념을 말함, 보통 class안에 new와 delete을 묶어놓음

void doSomething()
{
	try
	{
		//Resource* res = new Resource; // dull pointer : 멍청한 포인터 == delete를 써줘야하는 포인터
		AutoPtr<Resource> res(new Resource); // 직접 구현해본 smart pointer, direct initialization으로 하는 게 깔끔하다고 함, 필수는 아니고

		return;

		// work with res
		if (true)
		{
			//delete res; // 필요
			throw - 1;
			//return; // early return 때문에 delete이 제대로 안 되는 경우
		}

		//delete res; // 초보일 때 new로 동적 할당해놓고 delete을 안 하는 경우가 많음, 신경쓰자
		// 모던 c++로 갈수록 delete 대신, 스마트 포인터를 사용하면 편하다라는 식으로 많이 바뀌어 가고 있다고 함
	}
	catch (...)
	{
	}
	return;
}

int main()
{
	//doSomething();

	{
		AutoPtr<Resource> res1(new Resource); // int i; int* ptr(&i); int* ptr2 = nullptr; <- 대충 이런 구조
		AutoPtr<Resource> res2;

		cout << std::boolalpha;

		cout << res1.m_ptr << endl; // 주소 있음
		cout << res2.m_ptr << endl; // nullptr

		res2 = res1; // assignment overloading 발동 -> move semantics : 소유권 이전

		cout << res1.m_ptr << endl; // nullptr됨
		cout << res2.m_ptr << endl; // 주소 이전받음
	} // delete된 걸 또 지우는 일이 일어나면, 런타임 에러가 발생한다

	// syntax vs semantics

	// value semantics (copy semantics)
	// reference semantics (pointer)
	// move semantics (move)

	// 복잡한 경우에도 프로그래머들이 편하게 메모리 관리를 할 수 있도록
	// smart pointer, unique pointer, shared pointer 등이 생겼다

	return 0;
}