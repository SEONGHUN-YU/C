#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

// RAII : Resource Acquisition is initialization
// new�� ����� ������ delete�� �ؾ��Ѵٴ� ������ ����, ���� class�ȿ� new�� delete�� �������

void doSomething()
{
	try
	{
		//Resource* res = new Resource; // dull pointer : ��û�� ������ == delete�� ������ϴ� ������
		AutoPtr<Resource> res(new Resource); // ���� �����غ� smart pointer, direct initialization���� �ϴ� �� ����ϴٰ� ��, �ʼ��� �ƴϰ�

		return;

		// work with res
		if (true)
		{
			//delete res; // �ʿ�
			throw - 1;
			//return; // early return ������ delete�� ����� �� �Ǵ� ���
		}

		//delete res; // �ʺ��� �� new�� ���� �Ҵ��س��� delete�� �� �ϴ� ��찡 ����, �Ű澲��
		// ��� c++�� ������ delete ���, ����Ʈ �����͸� ����ϸ� ���ϴٶ�� ������ ���� �ٲ�� ���� �ִٰ� ��
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
		AutoPtr<Resource> res1(new Resource); // int i; int* ptr(&i); int* ptr2 = nullptr; <- ���� �̷� ����
		AutoPtr<Resource> res2;

		cout << std::boolalpha;

		cout << res1.m_ptr << endl; // �ּ� ����
		cout << res2.m_ptr << endl; // nullptr

		res2 = res1; // assignment overloading �ߵ� -> move semantics : ������ ����

		cout << res1.m_ptr << endl; // nullptr��
		cout << res2.m_ptr << endl; // �ּ� ��������
	} // delete�� �� �� ����� ���� �Ͼ��, ��Ÿ�� ������ �߻��Ѵ�

	// syntax vs semantics

	// value semantics (copy semantics)
	// reference semantics (pointer)
	// move semantics (move)

	// ������ ��쿡�� ���α׷��ӵ��� ���ϰ� �޸� ������ �� �� �ֵ���
	// smart pointer, unique pointer, shared pointer ���� �����

	return 0;
}