#include <iostream>
#include <memory>
#include <string>

class Person
{
private:
	std::string m_name;
	//std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner;

public:
	Person(const std::string& name)
		: m_name(name)
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is partnered with " << p2->m_name << '\n';

		return true;
	}

	const std::shared_ptr<Person> getPartner() const
	{
		return m_partner.lock(); // weak_ptr은 단점이 있는데, weak_ptr안의 내용물에 접근하려할 때
		// .lock()이라는 함수를 호출해서 shared_ptr로 바꿔준 다음에 사용해야만 하는 번거로움이 있다
		// 바꿔말하면, 순환 의존성을 깨기 위해서 이런 식으로 만들어져 있는 것
	}

	const std::string& getName() const
	{
		return m_name;
	}
};

int main()
{
	auto lucy = std::make_shared<Person>("Lucy");
	auto ricky = std::make_shared<Person>("Ricky");

	partnerUp(lucy, ricky); // 순환참조시킴 -> 문제 발생
	// 멤버변수를 weak_ptr로 바꿨더니 해결됨

	std::cout << lucy->getPartner()->getName() << std::endl;

	return 0;
}