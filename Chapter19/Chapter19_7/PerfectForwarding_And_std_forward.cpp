#include <iostream>
#include <vector>
#include <cstdio>
#include <utility> // std::forward

using namespace std;

struct MyStruct
{};

void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)
{
	cout << "Pass by R-ref" << endl;
}

//void func(MyStruct s)
//{
//	cout << "Pass by Value" << endl;
//}

// template�� ����� ���� l-ref, r-ref�� ������ �� ���ش�
//template<typename T> // templatize �Ǹ鼭 l-value���� r-value������ ���� ������ ���ư�����, �׷��� ������ �� �ϴ� ��
//void func_wrapper(T t)
//{
//	func(t);
//}

template<typename T>
void func_wrapper(T&& t) // �ذ��Ϸ��� perfect forwarding�� �ؾ��Ѵ�
{
	func(std::forward<T>(t)); // perfect forwarding�� �� ��
}

// ���⼭���ʹ� class�� ����� �ٸ� ����
class CustomVector
{
public:
	unsigned n_data = 0;
	int* ptr = nullptr;

	CustomVector(const unsigned& _n_data, const int& _init = 0)
	{
		cout << "Constructor" << endl;

		init(_n_data, _init);
	}

	CustomVector(CustomVector& l_input)
	{
		cout << "Copy constructor" << endl;

		init(l_input.n_data);

		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = l_input.ptr[i];
	}

	CustomVector(CustomVector&& r_input) noexcept
	{
		cout << "Move constructor" << endl;

		n_data = r_input.n_data;
		ptr = r_input.ptr;

		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	~CustomVector()
	{
		delete[] ptr;
	}

	void init(const unsigned& _n_data, const int& _init = 0)
	{
		n_data = _n_data;
		ptr = new int[n_data];

		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = _init;
	}
};

//void doSomething(CustomVector vec)
//{
//	cout << "Pass by Value" << endl;
//}

void doSomething(CustomVector& vec)
{
	cout << "Pass by L-reference" << endl;
	CustomVector new_vec(vec);
}

void doSomething(CustomVector&& vec)
{
	cout << "Pass by R-reference" << endl;
	CustomVector new_vec(std::move(vec)); // Note: vec itself is L-value
	//CustomVector new_vec(vec); // parameter�� &&�� �޾Ƶ� �����ڿ��� std::move�� ������ ������ l-value�� ����
	// Ư���� �����̴ϱ� ����ص� ��, std::move�� ����ϴ� �� ���������� ���鿡���� ������ ������ �鿩����
}

template<typename T>
void doSomethingTemplate(T&& vec) // template���� perfect forwarding�� �Ϸ��� &&�� �޾ƾ� �Ѵ�
//void doSomethingTemplate(T vec) // <- �̷��� ���� �� ��
{
	doSomething(std::forward<T>(vec)); // perfect forwarding
	//doSomething(vec); // <- �̷��� ���� �� ��
}

int main()
{
	{
		MyStruct s;
		func(s);
		func(MyStruct());

		func_wrapper(s);
		func_wrapper(MyStruct());
	}

	{
		CustomVector my_vec(10, 1024);

		//CustomVector temp(my_vec); // copy
		//CustomVector temp(std::move(my_vec)); // move
		//cout << my_vec.n_data << endl;

		doSomething(my_vec);
		doSomething(CustomVector(10, 8));

		doSomethingTemplate(my_vec);
		doSomethingTemplate(CustomVector(10, 8));
	}

	return 0;
}