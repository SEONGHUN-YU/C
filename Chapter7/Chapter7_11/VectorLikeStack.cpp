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
	//int *v_ptr = new int[3]{ 1,2,3 }; // ���������� ������ �̷� �����̴�
	std::vector<int> v{ 1,2,3 };
	// size, capacity(�뷮)
	// new�� delete�� ���� ������, ���� �� ���� �� ����

	//v.resize(2);
	v.reserve(1024); // �޸��� �뷮�� �̸� Ȯ���صΰڴٴ� �Լ�
	// �뷮�� Ȯ���Ǿ� ������ new�� delete �۾��� �� �Ѵ� -> �ξ� ������

	//for (auto& i : v)
	for (unsigned int i = 0; i < v.size(); ++i) // ������ �̷��� ���� �߾��ٰ� ��
		cout << v[i] << " ";
	cout << endl;
	cout << v.size() << " " << v.capacity() << endl;
	//cout << v.at(2) << endl;
	int* ptr = v.data();
	cout << ptr[2] << endl; // ������ ������ ��

	std::vector<int> stack; // ����Լ��� ������ �˰����� ����� �� stack overflow�� �����ϱ� ����
	stack.reserve(50); // vector�� stackó�� ����ϴ� ����� ����
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