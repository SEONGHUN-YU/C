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

	virtual void speak() const = 0; // pure virtual function : ���� �����Լ� 
	// definition(body: ���Ǻ�)�� ����

	/*virtual void speak() const // ���� ���
	{
		cout << m_name << " ???" << endl;
	}*/
};

/*void Animal::speak() const // the body of the pure virtual function
// ����� ���� �����Լ��� body�� �����س��� �� �����ϱ� ��
// �ٵ� ���� ��� �̷� ������ �� ��, �����غ��� ȣ���� ���� ����
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

// ������ʹ� interface ���
class IErrorLog // interface�� Ŭ������ �տ� I�� ���̴� ��ȭ�� ����
{
public:
	// Ŭ���� �ȿ� pure virtual function�ۿ� ������ interface class�� ��
	virtual bool reportError(const char* errorMessage) = 0;
	virtual ~IErrorLog() {} // �� �����, �Ҹ��ڴ� �׻� �������� �Ĳ��� ������ ��(interface class�� �ƴϴ���)
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
	//Animal ani("Hi"); // pure virtual function�� �������ν� abstract class�� ��
	// abstract class�� instance�� ���� ���� ����
	//ani.speak();

	Cow cow("hello"); // pure virtual function�� overriding �ϱ� ������ instance ���� �Ұ���
	cow.speak();

	// interface�� ��ӹ��� class�鵵 pure virtual function�� overriding �ϱ� ������ instance�� ������ �� ����
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);

	return 0;
}