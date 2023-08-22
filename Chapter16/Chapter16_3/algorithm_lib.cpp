#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	auto itr = min_element(container.begin(), container.end());
	cout << *itr << endl;

	itr = max_element(container.begin(), container.end());
	cout << *itr << endl;

	cout << endl;

	itr = find(container.begin(), container.end(), 3);
	container.insert(itr, 128);

	for (auto& e : container)
		cout << e << " ";
	cout << endl;

	//sort(container.begin(), container.end());
	container.sort(); // list는 sort랑 reverse가 내장되어 있다

	for (auto& e : container)
		cout << e << " ";
	cout << endl;

	//reverse(container.begin(), container.end());
	container.reverse(); // list는 이런 식으로 써야 함

	for (auto& e : container)
		cout << e << " ";
	cout << endl;

	return 0;
}