#include <iostream>

using namespace std;

class B; // forward declaration, 좋은 기능이긴 한데
// B의 존재가 어디 있는지 찾아야하기 때문에, 디버깅할 때랑, 코드 읽을 때 불편해진다는 단점이 있다
// 성향에 따라 안 쓰는 사람도 있지만, 복잡한 프로그램 같은 경우는 안 쓸 수가 없다고 한다
// 이걸 피할 방법이 있긴한데, 피하게 되면 코드가 너무 복잡해질 수 있다고 함
// 이렇다보니 부득이하게 많은 프로그래머들이 쓰고 있다는 듯
// 보통 friend를 쓸 때, 함께 자주 쓰인다는 것 같다


class A
{
private:
	int m_value = 1;

	friend void doSomething(A& a, B& b);
};
class B
{
private:
	int m_value = 2;

	friend void doSomething(A& a, B& b);
};
void doSomething(A& a, B& b)
{
	cout << a.m_value << " " << b.m_value << endl;
}


class C
{
private:
	int m_value = 3;
	
	friend class D;
};
class D
{
private:
	int m_value = 4;

public:
	void doSomething(C& c)
	{
		cout << c.m_value << endl;
	}
};


class E;
class F
{
private:
	int m_value = 6;

public:
	void doSomething(E& e);
};
class E
{
private:
	int m_value = 5;

	//friend class F; 에서 파생된, 더 접근을 제한시킨 버젼
	friend void F::doSomething(E& e);
};
void F::doSomething(E& e)
{
	cout << e.m_value << endl;
}

int main()
{
	A a;
	B b;
	doSomething(a, b);

	C c;
	D d;
	d.doSomething(c);

	E e;
	F f;
	f.doSomething(e);

	return 0;
}