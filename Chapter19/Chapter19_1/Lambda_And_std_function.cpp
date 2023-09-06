#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void goodbye(const string& s)
{
	cout << "Goodbye " << s << endl;
}

class Object
{
public:
	void hello(const string& s)
	{
		cout << "Hello " << s << endl;
	}
};

int main()
{
	// lambda-introducer : []
	// lambda-parameter-declaration : ()
	// lambda-return-type-clause : -> T
	// compound-statement : {}

	auto func = [](const int& i) -> void { cout << "Hello, World!" << endl; };

	func(123);

	[](const int& i) -> void { cout << "Hello, World!" << endl; }(1234);

	{
		string name = "JackJack";
		[&]() { cout << name << endl; }(); // 같은 스코프나 상위 스코프의 것들을 가져올 수 있게 해줌
		//[&name]() { cout << name << endl; }(); 이렇게 써도 됨
		//[this]() { cout << name << endl; }(); class의 멤버를 정의할 때는 이렇게도 쓸 수 있음
		//[=]() { cout << name << endl; }(); = 를 쓰면 copy를 함, 다만 &가 더 많이 쓰임
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	auto func2 = [](int val) { cout << val << endl; };
	for_each(v.begin(), v.end(), func2); // for_each는 algorithm에 들어 있음
	for_each(v.begin(), v.end(), [](int val) { cout << val << endl; });

	cout << []() -> int { return 1; }() << endl;

	std::function<void(int)> func3 = func2;
	func3(123);

	// 재밌는 건 void(void)로 써도 에러 안 나는 듯
	std::function<void()> func4 = std::bind(func3, 456); // func3의 (int)를 그냥 바로 넣어주면서, template parameter에서 생략할 수 있게 만듬
	func4(); // 그리고 바로 실행

	// https://en.cppreference.com/w/cpp/utility/functional/placeholders
	{
		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f(string("World")); // parameter 넣어주는 곳, string이라는 걸 강조하기 위해 그냥 생성자를 써 봄, 없어도 됨

		auto f2 = std::bind(&goodbye, std::placeholders::_1);

		f2(string("World"));
	}

	return 0;
}