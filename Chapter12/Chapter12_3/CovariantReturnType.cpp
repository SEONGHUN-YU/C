#include <iostream>

using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
	virtual A* getThis()
	{
		cout << "A::getThis()" << endl;
		return this;
	}
};

class B : public A
{
public:
	void print() { cout << "B" << endl; } // parameter가 다르면, 오버라이딩할 수가 없음
	// parameter가 다르면, 컴파일러가 오버로딩으로 간주해버림, 즉 A의 함수를 실행하려고 하려나보다 하고 A의 함수를 실행하는 것
	// 이런 상황을 막으려면 override 키워드를 넣어주면 컴파일되기 전에 잡아줄 수 있다
	// final 키워드를 쓰면, 밑의 클래스들이 오버라이딩 불가능하게 된다
	// final과 override는 가상함수(또는 오버라이딩된 가상함수)에만 쓸 수 있다

	virtual B* getThis()
	{
		cout << "B::getThis()" << endl;
		return this;
	}
	// 원래는 return 타입이 다르면 오버라이딩이 안 되는데
	// 상속관계여서 참조는 return 타입이 달라도 오버라이딩이 되는 것 같음
	// 근데, 실행하면 B의 것으로 접속해서 A의 주소를 return하는 아이러니한 상황이 펼쳐짐, 이런 걸
	// covariant return type : 공변 반환값 <- 라고 하는 것 같음
};

class C : public B
{
public:
	//virtual void print(int x) { cout << "C" << endl; }
	// final 때문에 오버라이딩이 안 되는 모습
};

int main()
{
	A a;
	B b;
	//C c;

	A& ref = b;
	b.getThis()->print();
	ref.getThis()->print();

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;

	return 0;
}