#include <iostream>
#include <vector>
#include <algorithm> // std::min()

// Reference : https://thbecker.net/articles/auto_and_decltype/section_01.html

using namespace std;

class Examples
{
public:

	void ex1()
	{
		vector<int> vect;
		for (vector<int>::iterator itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;

		for (auto itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;

		for (auto itr : vect) // for (const auto& itr : vect)
			cout << itr;
	}

	void ex2()
	{
		int x = int();

		auto auto_x = x;

		const int& crx = x;

		auto auto_crx1 = crx; // auto는 추론을 할 때, const나 & 같은 걸 다 떼버린다, 그래서 그냥 int가 되어버림
		// auto의 매우 중요한 성질

		const auto& auto_crx2 = crx;

		volatile int vx = 1024;

		auto avx = vx;

		volatile auto vavx = vx;
	}

	/*template<class T>
	void func_ex3(T arg)
	{}*/

	template<class T>
	void func_ex3(const T& arg) // template의 type deduction(타입 추론)도 auto와 비슷한 성질을 가진다
	{}

	void ex3()
	{
		const int& crx = 123;

		func_ex3(crx);
	}

	void ex4()
	{
		const int c = 0;
		auto& rc = c; // 이렇게 &로 const를 가져오는 경우엔 똑똑하게 const int&로 가져온다
		//rc = 123; // error
	}

	void ex5() // amendment : 개정, <- 알아서 수정을 해줌
	{
		int i = 42;
		auto&& ri_1 = i; // &&로 받고있지만 l-value가 들어와서 l-value로 받아줌
		auto&& ri_2 = 42; // &&로 받는데 r-value라서 문제없이 잘 받아줌
	}

	void ex6()
	{
		int x = 42;
		const int* p1 = &x;
		auto p2 = p1; // pointer일 때는 모든 성질을 다 가져온다
		//*p2 = 43; // error
	}

	template<typename T, typename S>
	void func_ex7(T lhs, S rhs)
	{
		auto prod1 = lhs * rhs; // auto가 반드시 필요한 경우

		//typedef typeof(lhs * rhs) product_type; // pre-c++11 'some' compilers
		typedef decltype(lhs* rhs) product_type; // decltype() 안에서는 어떤 type이 나올지 추론만하고 실제로 계산은 하지 않는다

		product_type prod2 = lhs * rhs;

		decltype(lhs * rhs) prod3 = lhs * rhs; // typedef를 사용하지 않고 직접, 자료형 자리에 넣어줘도 된다
	}

	template<typename T, typename S>
	//decltype(lhs * rhs) func_ex8(T lhs, S rhs) // <- 컴파일러가 코드를 읽는 순서상, 이렇게는 불가능하다고 함
	auto func_ex8(T lhs, S rhs) -> decltype(lhs* rhs) // -> type : trailing return type 이라고 부른다
	{
		return lhs * rhs;
	}

	void ex7_8()
	{
		func_ex7(1.0, 345);
		func_ex8(1.2, 345);
	}

	struct S
	{
		int m_x;

		S()
		{
			m_x = 42;
		}
	};

	void ex9()
	{
		int x;
		const int cx = 42;
		const int& crx = x;
		const S* p = new S();

		auto a = x;
		auto b = cx;
		auto c = crx;
		auto d = p;
		auto e = p->m_x;

		typedef decltype(x)		 x_type;
		typedef decltype(cx)	 cx_type;
		typedef decltype(crx)	 crx_type; // decltype은 auto와 다르게 선언이 된 type을 그대로 가져온다
		typedef decltype(p->m_x) m_x_type; // 'declared' type : m_x가 struct안에서 선언이 될 때는 int로 선언이 되었기 때문에 int로 가져옴

		typedef decltype((x))		x_with_parens_type; // add references to l-values
		typedef decltype((cx))		cx_with_parens_type; // decltype(())로 가져오면 &을 붙여서 가져온다
		typedef decltype((crx))		crx_with_parens_type; // 하지만 &이 &&이 되지는 않는다
		typedef decltype((p->m_x))	m_x_with_parens_type; // &가 되었기 때문에, 변할 수 없다고 하는 const의 조건을 함께 가져왔다
		// 이 부분은 기억해두자
	}

	const S foo()
	{
		return S();
	}

	const int& foobar()
	{
		return 123;
	}

	void ex10()
	{
		vector<int> vect = { 42, 43 };

		auto a = foo();
		typedef decltype(foo()) foo_type;

		auto b = foobar();
		typedef decltype(foobar()) foobar_type;

		auto itr = vect.begin();
		typedef decltype(vect.begin()) iterator_type;

		auto first_element = vect[0];
		decltype(vect[1]) second_element = vect[1]; // []는 <int>, 즉 int의 ref를 return하는 녀석이다
	}

	void ex11()
	{
		int x = 0;
		int y = 0;
		const int cx = 42;
		const int cy = 43;
		double d1 = 3.14;
		double d2 = 2.72;

		typedef decltype(x* y) prod_xy_type;
		auto a = x * y;

		typedef decltype(cx* cy) prod_cxcy_type; // result is pure-r-value
		auto b = cx * cy;

		typedef decltype(d1 < d2 ? d1 : d2) cond_type; // result is l-value, & is added : 삼항연산자에서 비교하는 대상의 타입이 같을 경우에는 return되는 결과에 &가 붙는다
		// 아주 특이하다
		auto c = d1 < d2 ? d1 : d2;

		typedef decltype(x < d2 ? x : d2) cond_type_mixed; // promotion of x to double
		auto d = x < d2 ? x : d2;

		// auto e = std::min(int, double); // error <- min()은 2개의 arguments가 type이 같을 경우에만 작동을 한다
	}

	template<typename T, typename S> // 비교하는 타입이 같을 경우에는 return되는 타입에 &가 붙는다
	auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y) // fp는 floating point의 의미
	{
		return x < y ? x : y;
	}

	template<typename T, typename S>
	auto fpmin(T x, S y) -> typename std::remove_reference<decltype(x < y ? x : y)>::type // 위의 문제를 해결한 방법, reference를 뗀(제거된) 타입을 사용하게 만들어 줌
	{
		return x < y ? x : y;
	}

	void ex12()
	{
		int i = 42;
		double d = 45.1;
		// auto a = std::min(i, d); // error <- 'std::min': no matching overloaded function found
		auto a = std::min(static_cast<double>(i), d);

		int& j = i;

		typedef decltype(fpmin_wrong(d, d)) fpmin_return_type1;
		typedef decltype(fpmin_wrong(i, d)) fpmin_return_type2;
		typedef decltype(fpmin_wrong(j, d)) fpmin_return_type3;
	}

	void ex13()
	{
		vector<int> vect; // vect is empty
		typedef decltype(vect[0]) integer; // decltype은 ()을 실제로 수행(계산)을 하지는 않기 때문에, 비어있어도 type을 return 해줄 수 있다 <- compile time에 결정됨
	}

	template<typename R>
	class SomeFunctor
	{
	public:
		typedef R result_type;

		SomeFunctor()
		{}

		result_type operator() ()
		{
			return R();
		}
	};

	void ex14()
	{
		SomeFunctor<int> func;
		typedef decltype(func)::result_type integer; // nested type
	}

	void ex15()
	{
		auto lambda = []() { return 42; };
		decltype(lambda) lambda2(lambda);
		decltype((lambda)) lambda3(lambda);

		cout << "Lambda functions" << endl;
		cout << &lambda << " " << &lambda2 << endl; // 주소가 다름
		cout << &lambda << " " << &lambda3 << endl; // ref여서 주소가 같음
	}

	void ex16()
	{
		// generic lambda
		auto lambda = [](auto x, auto y) { return x + y; };
		// 일반 함수에서는 parameter에 auto를 못 쓰는데, lambda에서는 auto를 쓸 수 있다

		cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.5, 2.2) << endl;
	}
};

int main()
{
	Examples examples;

	return 0;
}