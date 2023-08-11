#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	~A()
	{
		//throw "error"; // �Ҹ��� �ȿ��� throw�� �ϴ� ���� ���� ������ ��, �ݱ�õǴ� ����
	} // �Ҹ��ڿ����� ���ܸ� ������ �� ��ü�� �Ұ��� ��
};

int main()
{
	try
	{
		int* i = new int[1000000];
		unique_ptr<int> up_i(i); // block(����)�� �����, unique �����Ͱ� �˾Ƽ� �޸𸮸� �����شٰ� ��
		// throw�Ǵ��� ���������� �˾Ƽ� �޸𸮸� ������ -> delete[] �� ���൵ ��

		// do something with i
		throw "error";
		//delete[] i; // throw ������ memory leak�� ���� �� ����

		A a;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;
}