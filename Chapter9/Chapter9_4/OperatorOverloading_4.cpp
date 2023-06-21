#include <iostream>
#include <vector>>
#include <algorithm>
#include <random>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend bool operator== (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}
	
	friend bool operator!= (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents != c2.m_cents;
	}

	friend bool operator< (const Cents& c1, const Cents& c2) // std::sort() 사용할 때는 <(lt) 연산자를 오버로딩해야 한다
	{
		return c1.m_cents < c2.m_cents; // 여기서 <는 오름차순, >는 내림차순으로 sort된다
	}

	friend std::ostream& operator<< (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out;
	}
};

int main()
{
	Cents cents1(6);
	Cents cents2(0);
	if (cents1 == cents2)
		cout << "Equal" << endl;
	cout << std::boolalpha;

	vector<Cents> arr(20);
	for (unsigned int i = 0; i < 20; ++i)
		arr[i].getCents() = i;

	std::random_shuffle(begin(arr), end(arr));
	/*std::random_device rd; // c++17이상부터 random_shuffle이 없어져서
	std::mt19937 g(rd()); // 이렇게 random_device를 이용해야 함
	std::shuffle(arr.begin(), arr.end(), g);*/

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	std::sort(begin(arr), end(arr));

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	return 0;
}