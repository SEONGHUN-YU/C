#include <iostream>
#include <vector>

using namespace std;

void printStack(const std::vector<int>& stack)
{
	for (auto& i : stack)
		cout << i << " ";
	cout << endl;
}

int main()
{
	//int *v_ptr = new int[3]{ 1,2,3 }; // 동일하지는 않지만 이런 느낌이다
	std::vector<int> v{ 1,2,3 };
	// size, capacity(용량)
	// new와 delete는 많이 느리다, 많이 안 쓰는 게 좋다

	//v.resize(2);
	v.reserve(1024); // 메모리의 용량을 미리 확보해두겠다는 함수
	// 용량이 확보되어 있으면 new와 delete 작업을 안 한다 -> 훨씬 빨라짐

	//for (auto& i : v)
	for (unsigned int i = 0; i < v.size(); ++i) // 예전엔 이렇게 많이 했었다고 함
		cout << v[i] << " ";
	cout << endl;
	cout << v.size() << " " << v.capacity() << endl;
	//cout << v.at(2) << endl;
	int* ptr = v.data();
	cout << ptr[2] << endl; // 억지로 가져온 것

	std::vector<int> stack; // 재귀함수로 구현한 알고리즘을 사용할 때 stack overflow를 방지하기 위해
	stack.reserve(50); // vector를 stack처럼 사용하는 방법이 있음
	stack.push_back(3);
	printStack(stack);
	stack.push_back(5);
	printStack(stack);
	stack.push_back(7);
	printStack(stack);
	stack.pop_back();
	printStack(stack);
	stack.pop_back();
	printStack(stack);
	stack.pop_back();
	printStack(stack);

	return 0;
}