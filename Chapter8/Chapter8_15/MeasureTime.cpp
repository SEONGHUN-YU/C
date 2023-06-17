#include <iostream>
#include <vector>
#include <algorithm> // sort()�� ���� ���� ������
#include <random>
#include <chrono> // �ð� ���ִ� lib

using namespace std;

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;
	std::chrono::time_point<clock_t> start_time = clock_t::now(); // ������ �ð� ����

public:
	void elapsed()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now(); // ���� �ð� ����
		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
		// �ʴ���(���� �ð� - ������ �ð�) ��ȯ ��Ű��, .count()�� ���
	}
};

int main()
{
	random_device rnd_device;
	mt19937_64 mersenne_engine{ rnd_device() };

	vector<int> vec(10000);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	std::shuffle(begin(vec), end(vec), mersenne_engine); // �����̳��� ������ ������

	/*for (auto& e : vec) cout << e << " "; // ���� ���� ���
	cout << endl;*/

	Timer timer; // �ð� ��� ������

	std::sort(begin(vec), end(vec)); // sorting
	
	timer.elapsed(); // �� �ð� ���

	/*for (auto& e : vec) cout << e << " "; // sorting�� ��� ���
	cout << endl;*/

	return 0;
}