#include <iostream>
#include <vector>
#include <algorithm> // sort()를 쓰기 위해 가져옴
#include <random>
#include <chrono> // 시간 재주는 lib

using namespace std;

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;
	std::chrono::time_point<clock_t> start_time = clock_t::now(); // 시작한 시간 찍음

public:
	void elapsed()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now(); // 끝난 시간 찍음
		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
		// 초단위(끝난 시간 - 시작한 시간) 변환 시키고, .count()로 출력
	}
};

int main()
{
	random_device rnd_device;
	mt19937_64 mersenne_engine{ rnd_device() };

	vector<int> vec(10000);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	std::shuffle(begin(vec), end(vec), mersenne_engine); // 컨테이너의 순서를 섞어줌

	/*for (auto& e : vec) cout << e << " "; // 섞인 순서 출력
	cout << endl;*/

	Timer timer; // 시간 재기 시작함

	std::sort(begin(vec), end(vec)); // sorting
	
	timer.elapsed(); // 잰 시간 출력

	/*for (auto& e : vec) cout << e << " "; // sorting된 결과 출력
	cout << endl;*/

	return 0;
}