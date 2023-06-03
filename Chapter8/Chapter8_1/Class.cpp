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
public: // access specifier : 접근 지정자 (public, private, protected)
	string m_name; // m_name, name_, _name 같은 스타일이 있는데 _만 붙이는 스타일이 좀 더 최신이라는 것 같다
	string address_; // 멤버라는 걸 표현하기 위해서 m_을 붙인 것
	int _age;
	double height;
	double weight;
	void print()
	{
		cout << m_name << " " << address_ << " " << _age << " " << height << " " << weight << endl;
	}
};

// 단순한 기능만 할 때는 struct를 써도 괜찮다
// 일반적으로 데이터만 묶어넣을 때는 struct를 쓰고 (함수를 넣지 않음), 기능(함수)까지 넣을 때는 class를 쓴다
// c에서는 struct안에 함수를 못 넣는다는 것 같다
// c++에서는 struct안에도 함수가 들어갈 수 있다

int main()
{
	// class를 정의하는 것만으로는 메모리를 차지하지 않는데,
	Friend jj{ "Jack Jack", "Uptown", 2, 30, 5 }; // <- instanciation : 실제로 메모리를 차지하도록 정의해주는 것
	cout << &jj << endl; // jj를 instance라고 부른다

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