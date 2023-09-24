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

// template을 사용할 때는 l-ref, r-ref를 구분을 안 해준다
//template<typename T> // templatize 되면서 l-value인지 r-value인지에 대한 정보가 날아가버림, 그래서 구분을 못 하는 것
//void func_wrapper(T t)
//{
//	func(t);
//}

template<typename T>
void func_wrapper(T&& t) // 해결하려면 perfect forwarding을 해야한다
{
	func(std::forward<T>(t)); // perfect forwarding을 한 것
}

// 여기서부터는 class를 사용한 다른 예제
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
	//CustomVector new_vec(vec); // parameter로 &&로 받아도 생성자에서 std::move를 해주지 않으면 l-value로 들어간다
	// 특이한 성질이니까 기억해둘 것, std::move를 사용하는 게 가독성적인 측면에서도 좋으니 습관을 들여놓자
}

template<typename T>
void doSomethingTemplate(T&& vec) // template에서 perfect forwarding을 하려면 &&로 받아야 한다
//void doSomethingTemplate(T vec) // <- 이러면 구분 못 함
{
	doSomething(std::forward<T>(vec)); // perfect forwarding
	//doSomething(vec); // <- 이러면 구분 못 함
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