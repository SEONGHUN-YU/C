#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const string& name, const string& address, const int& age,
	const double& height, const double& weight)
{
	cout << name << " " << address << " " << age << " " << height << " " << weight << endl;
}

// Object
// Friend : name, address, age, height
//			print()

class Friend
{
public: // access specifier : ���� ������ (public, private, protected)
	string m_name; // m_name, name_, _name ���� ��Ÿ���� �ִµ� _�� ���̴� ��Ÿ���� �� �� �ֽ��̶�� �� ����
	string address_; // ������ �� ǥ���ϱ� ���ؼ� m_�� ���� ��
	int _age;
	double height;
	double weight;
	void print()
	{
		cout << m_name << " " << address_ << " " << _age << " " << height << " " << weight << endl;
	}
};

// �ܼ��� ��ɸ� �� ���� struct�� �ᵵ ������
// �Ϲ������� �����͸� ������� ���� struct�� ���� (�Լ��� ���� ����), ���(�Լ�)���� ���� ���� class�� ����
// c������ struct�ȿ� �Լ��� �� �ִ´ٴ� �� ����
// c++������ struct�ȿ��� �Լ��� �� �� �ִ�

int main()
{
	// class�� �����ϴ� �͸����δ� �޸𸮸� �������� �ʴµ�,
	Friend jj{ "Jack Jack", "Uptown", 2, 30, 5 }; // <- instanciation : ������ �޸𸮸� �����ϵ��� �������ִ� ��
	cout << &jj << endl; // jj�� instance��� �θ���

	/*jj.name = "Jack Jack";
	jj.age = 2;*/

	vector<Friend> my_friends;
	my_friends.resize(2);
	for (auto& o : my_friends)
		o.print();

	print(jj.m_name, jj.address_, jj._age, jj.height, jj.weight);
	//print(jj);
	jj.print();

	/*vector<string> name_vec;
	vector<string> addr_vec;
	vector<int> age_vec;
	vector<double> height_vec;
	vector<double> weight_vec;
	//print(name_vec[0], addr_vec[0], age_vec[0], height_vec[0], weight_vec[0]);*/

	return 0;
}