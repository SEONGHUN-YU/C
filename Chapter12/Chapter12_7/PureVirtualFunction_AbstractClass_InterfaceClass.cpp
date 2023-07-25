#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	std::string m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{}

public:
	std::string getName() { return m_name; }

	virtual void speak() const = 0; // pure virtual function : 순수 가상함수 
	// definition(body: 정의부)가 없음

	/*virtual void speak() const // 원래 모습
	{
		cout << m_name << " ???" << endl;
	}*/
};

/*void Animal::speak() const // the body of the pure virtual function
// 사실은 순수 가상함수도 body를 정의해놓는 게 가능하긴 함
// 근데 쓸모가 없어서 이런 식으로 안 씀, 구현해봤자 호출할 수가 없음
{
	cout << m_name << " ???" << endl;
}*/

class Cat : public Animal
{
public:
	Cat(std::string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(std::string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof" << endl;
	}
};

class Cow : public Animal
{
public:
	Cow(std::string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Moooo" << endl;
	}
};

// 여기부터는 interface 얘기
class IErrorLog // interface는 클래스명 앞에 I를 붙이는 문화가 있음
{
public:
	// 클래스 안에 pure virtual function밖에 없으면 interface class가 됨
	virtual bool reportError(const char* errorMessage) = 0;
	virtual ~IErrorLog() {} // 뭘 만들든, 소멸자는 항상 잊지말고 꼼꼼히 구현할 것(interface class가 아니더라도)
};

class FileErrorLog : public IErrorLog
{
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error!!");
}

int main()
{
	//Animal ani("Hi"); // pure virtual function을 가짐으로써 abstract class가 됨
	// abstract class라서 instance를 만들 수가 없음
	//ani.speak();

	Cow cow("hello"); // pure virtual function을 overriding 하기 전까진 instance 생성 불가능
	cow.speak();

	// interface를 상속받은 class들도 pure virtual function을 overriding 하기 전까진 instance를 생성할 수 없음
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);

	return 0;
}