#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <atomic>
#include <mutex>
#include <thread>
#include <future>
#include <utility>
#include <numeric> // std::inner_product
#include <execution> // parallel execution

using namespace std;

mutex mtx; // 꼭 전역변수로 할 필요는 없다

void dotProductNaive(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	for (unsigned i = i_start; i < i_end; ++i)
		sum += v0[i] * v1[i];
}

void dotProductLock(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	//std::lock_guard<mutex> lock(mtx); for문 밖에 둔 것과 안에 둔 것은 차이가 있다
	// for문 밖에 두면 의미가 없다, 나머지 thread는 놀고 있다는 뜻, thread를 생성하는 오버헤드만 커짐
	// 동시적으로 실행된 것(병렬)이 아니라, lock_guard가 전체에 걸려서, 순차적으로 실행되기 때문

	cout << "Thread start" << endl;

	for (unsigned i = i_start; i < i_end; ++i)
	{
		//std::lock_guard<mutex> lock(mtx); // lock은 작은 영역에 거는 게 좋음
		// 다만 lock이 걸리는 부분이 너무 자주 실행되면 오히려 느려짐, multi-threading을 안 하느니만 못하다
		std::scoped_lock lock(mtx); // c++17부터 가능

		sum += v0[i] * v1[i];
	}

	cout << "Thread end" << endl;
}

void dotProductAtomic(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, atomic<unsigned long long>& sum)
{
	for (unsigned i = i_start; i < i_end; ++i)
		sum += v0[i] * v1[i]; // atomic도 일반 연산보다는 느리기 때문에, 빈번하게 호출되는 곳에 atomic은 퍼포먼스가 떨어진다
}

auto dotProductFuture(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end)
{
	int sum = 0; // local sum
	for (unsigned i = i_start; i < i_end; ++i)
		sum += v0[i] * v1[i];
	return sum;
}

int main()
{
	/*v0 = { 1, 2, 3 }
	v1 = { 4, 5, 6 }
	v0_dot_v1 = 1*4 + 2*5 + 3*6;*/

	const long long n_data = 100'000'000;
	const unsigned n_threads = 4;

	// initialize vectors
	vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);

	random_device seed;
	mt19937 engine(seed());

	uniform_int_distribution<> uniformDist(1, 10);

	for (long long i = 0; i < n_data; ++i)
	{
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}

	cout << "std::inner_product" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	cout << "Naive" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	cout << "Lockguard" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	
	cout << "Atomic" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		atomic<unsigned long long> sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	cout << "Future" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<std::future<int>> futures; // 다른 부분 ★
		futures.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
		for (unsigned t = 0; t < n_threads; ++t)
			futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1), // future일 때는 async로 해줄 것
				t * n_per_thread, (t + 1) * n_per_thread); // 다른 부분 ★

		for (unsigned t = 0; t < n_threads; ++t)
			sum += futures[t].get(); // 다른 부분 ★

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	cout << "std::transform_reduce" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		//const auto sum = std::transform_reduce(std::execution::seq, v0.begin(), v0.end(), v1.begin(), 0ull); // 순차적 ::seq
		const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull); // 동시적 ::par
		// transform_reduce : c++17부터 가능

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	//TODO: use divide and conquer strategy for std::thread
	//TODO: use promise

	return 0;
}