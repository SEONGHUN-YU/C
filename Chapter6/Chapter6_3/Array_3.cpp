#include <iostream>

using namespace std;

int main()
{
	int scores[]{ 84, 92, 76, 81, 56 };
	const int num_students = sizeof(scores) / sizeof(int); // parameter로 넘어간 배열은 포인터라서, 이 식이 성립이 안 된다
	int total_score = 0, max_score = 0;
	for (int i = 0; i < num_students; i++) 
	{
		total_score += scores[i];
		max_score = max_score > scores[i] ? max_score : scores[i];
	}
	double avg_score = static_cast<double>(total_score) / num_students;
	// double(total_score) / num_students != double(total_score / num_students)
	cout << avg_score << endl;
	return 0;
}