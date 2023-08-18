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
		return m_partner.lock(); // weak_ptr�� ������ �ִµ�, weak_ptr���� ���빰�� �����Ϸ��� ��
		// .lock()�̶�� �Լ��� ȣ���ؼ� shared_ptr�� �ٲ��� ������ ����ؾ߸� �ϴ� ���ŷο��� �ִ�
		// �ٲ㸻�ϸ�, ��ȯ �������� ���� ���ؼ� �̷� ������ ������� �ִ� ��
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

	partnerUp(lucy, ricky); // ��ȯ������Ŵ -> ���� �߻�
	// ��������� weak_ptr�� �ٲ���� �ذ��

	std::cout << lucy->getPartner()->getName() << std::endl;

	return 0;
}