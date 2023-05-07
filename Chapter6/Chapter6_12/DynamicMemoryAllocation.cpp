#include <iostream>

using namespace std;

int main()
{
	// 메모리 할당은 3종류로 나뉜다
	// 1. static memory allocation : 정적 메모리 할당
	// 전역 변수, static 변수, 한 번 만들면
	// 프로그램이 끝날 때까지 계속 메모리를 가지고 있는다

	// 2. 자동 메모리 할당 : stack영역에 들어감
	// 변수를 선언, 정적 배열을 선언을 했을 때 블록 밖으로 나가면
	// 전부 사라지고 메모리가 OS로 할당(반납)된다

	// 3. dynamic memory allocation : 동적 메모리 할당

	// stack은 메모리 크기가 작다, heap은 메모리 크기가 크다
	// 따라서 동적 할당으로 heap영역 사용은 필수적이다

	/*int var;
	var = 7;*/
	int* ptr = new (std::nothrow) int{ 7 }; // 타입 사이즈만큼, OS에게 메모리를 받아와서 그 메모리 주소를 알려준다
	// => 따라서 포인터로 받아야 함
	//*ptr = 7; // 위의 선언과 초기화랑 같은 거임

	/*int* ptr2 = new int(10); // 포인터로 메모리를 할당하면서 동시에 초기화도 시켜줄 수 있다
	int* ptr3 = new int{ 20 }; // 2가지 방법*/
	int* ptr2 = ptr;
	delete ptr; // <- 흔히 하는 실수
	ptr = nullptr;
	ptr2 = nullptr; // 이 경우, 얘도 nullptr 해줘야 함, 잘 까먹는다 함

	if (ptr) // ptr != nullptr 이랑 똑같이 작동함
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}
	else
	{
		cout << "Could not allocate memory" << endl;
	}

	delete ptr; // OS에게 메모리를 돌려주는(반납) 방법
	ptr = nullptr; // 삭제한 포인터에 0 또는 NULL 또는 nullptr(추천)을 넣어주어 값이 없다고 명시해준다

	// delete를 쓰지 않아도 아무 문제 없었는데, 그 이유는 OS가
	// 어떤 프로그램에 메모리를 얼만큼 줬었다 하는 사실을 기억하고 있다가 
	// 그 프로그램이 종료됨과 동시에 자동으로 알아서 걷어갔기 때문
	
	// delete를 쓰면 프로그램이 종료되기 전에, 먼저 반납하겠다는 의미

	cout << "After delete" << endl;
	if (ptr != nullptr) // 중요한 트릭
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}

	// memory leak : 메모리 누수
	/*while (1)
	{
		int* ptr = new int; // 포인터를 써서 동적 할당을 할 때, 지우는 걸 깜빡하는 실수
		cout << ptr << endl;
		delete ptr;
	}*/

	// new와 delete은 아무래도 OS를 한 번 거쳐야 하기 때문에 stack보다 느리다(비교적)
	// stack으로만 짠 코드가 속도는 더 빠르다는 듯하다, 그러나 메모리가 모자랄 것

	return 0;
}