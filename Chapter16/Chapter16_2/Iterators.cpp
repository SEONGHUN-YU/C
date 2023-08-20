#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
	{
		vector<int> container;
		for (int i = 0; i < 10; ++i)
			container.push_back(i);

		vector<int>::const_iterator itr;
		itr = container.begin();
		while (itr != container.end())
		{
			cout << *itr << " ";
			++itr;
		}
		cout << endl;

		for (auto itr = container.begin(); itr != container.end(); ++itr)
			cout << *itr << " ";
		cout << endl;

		for (auto& e : container)
			cout << e << " ";
		cout << endl;
	}

	{
		list<int> container;
		for (int i = 0; i < 10; ++i)
			container.push_back(i);

		for (auto itr = container.begin(); itr != container.end(); ++itr)
			cout << *itr << " ";
		cout << endl;

		for (auto& e : container)
			cout << e << " ";
		cout << endl;
	}

	{
		set<int> container;
		for (int i = 0; i < 10; ++i)
			container.insert(i);

		for (auto itr = container.begin(); itr != container.end(); ++itr)
			cout << *itr << " ";
		cout << endl;

		for (auto& e : container)
			cout << e << " ";
		cout << endl;
	}

	{
		map<int, char> container;
		for (int i = 0; i < 10; ++i)
			//container.insert(pair<int, char>(i, char(i + 97))); // �⺻ ���
			container.insert(make_pair(i, char(i + 97))); // �̷� ��ĵ� ����
		
		for (auto itr = container.begin(); itr != container.end(); ++itr)
			//cout << (*itr).first << " " << (*itr).second << endl; // �̷� ��ĵ� ����
			cout << itr->first << " " << itr->second << endl; // �⺻ ���
		cout << endl;
	}

	return 0;
}