#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void sequence_containers()
{
	// vector
	{
		vector<int> vec; // #include <vector>
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);

		for (auto& e : vec)
			cout << e << " ";
		cout << '\n';
	}
	
	// deque
	{
		deque<int> deq; // #include <deque>
		for (int i = 0; i < 10; ++i)
		{
			deq.push_back(i);
			deq.push_front(i);
		}

		for (auto& e : deq)
			cout << e << " ";
		cout << '\n';
	}
}

void associative_containers()
{
	// set
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl;
		
		for (auto& e : str_set)
			cout << e << " ";
		cout << '\n';
	}

	// multiset : duplication is allowed
	{
		multiset<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (auto& e : str_set)
			cout << e << " ";
		cout << '\n';
	}

	// map : key/value
	{
		map<char, int> map;
		map['c'] = 50;
		map['a'] = 10;
		map['b'] = 20;
		
		cout << map['a'] << endl;

		map['a'] = 100;

		cout << map['a'] << endl;

		for (auto& e : map)
			cout << e.first << " " << e.second << " ";
		cout << '\n';
	}

	// multimap : duplicated keys
	{
		multimap<char, int> map;
		//map.insert(std::pair('a', 10)); // c++14보다 높은 버전에서는 이런 식으로도 넣을 수 있음
		//map.insert(std::pair('b', 10));
		//map.insert(std::pair('c', 10));
		//map.insert(std::pair('a', 100));
		map.insert(pair<char, int>('a', 10)); // c++14까지는 pair<char, int>('a', 10); 로 넣어야 함
		map.insert(pair<char, int>('b', 10)); // template parameter를 명확하게 표기해주어야 넣어짐
		map.insert(pair<char, int>('c', 10));
		map.insert(pair<char, int>('a', 100));

		cout << map.count('a') << endl;

		for (auto& e : map)
			cout << e.first << " " << e.second << " ";
		cout << '\n';
	}
}

void container_adapters()
{
	// stack
	{
		cout << "Stack" << endl;

		stack<int> stack;
		stack.push(1); // push adds a copy
		stack.emplace(2); // emplace constructs a new object
		stack.emplace(3);
		cout << stack.top() << endl;
		stack.pop();
		cout << stack.top() << endl;
	}

	// queue
	{
		cout << "Queue" << endl;

		queue<int> queue;
		queue.push(1);
		queue.push(2);
		queue.push(3);
		cout << queue.front() << " " << queue.back() << endl;
		queue.pop();
		cout << queue.front() << " " << queue.back() << endl;
	}

	// priority queue : sorting이 됨
	{
		cout << "Priority queue" << endl;

		priority_queue<int> queue;

		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			queue.push(n);

		for (int i = 0; i < 10; ++i)
		{
			cout << queue.top() << endl;
			queue.pop();
		}
	}
}

int main()
{
	sequence_containers();

	associative_containers();

	container_adapters();

	return 0;
}