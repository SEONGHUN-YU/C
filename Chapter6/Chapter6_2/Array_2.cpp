#include <iostream>

using namespace std;

#define NUM_STUDENTS 10000

void doSomething(int students_scores[]) // 얘는 배열이 아니다, 진짜 정체는 포인터다 (어차피 포인터로 받아올 거여서 size는 비워놔도 된다)
{	// 컴파일러는 내부적으로 얘를 포인터로 처리한다
	// 배열의 모든 원소를 복사해서 가져오는 것이 아니라, parameter로 가져올 때, 배열의 첫번째 주소값만 복사해온다
	// 넘겨받은, 배열의 첫번째 주소값을 저장하는 포인터 변수이기 때문에, 그 자체가 다른 주소값을 가진다
	// => 주소값을 저장하는, 다른 변수,의 주소가 출력되는 것
	// 그래서 parameter로, 배열을 포인터를 사용하여 직접 받는 것 또한 가능하다

	cout << (long long)&students_scores << endl;
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	cout << "func " << sizeof(students_scores) << endl;
}

int main()
{
	const int num_students = 20;
	int students_scores[num_students]{ 1, 2, 3, 4, 5 }; // []랑 subscript라는 게 연관이 있는 듯?

	// 배열의 경우, 식별자명 자체가 내부적으로 주소로 사용되기 때문에
	// &없이 캐스팅만 해줘도 주소가 나온다, 물론 &를 붙여도 상관없다
	// 주소로 데이터를 주고 받는다
	cout << (long long)students_scores << endl;
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	cout << "main " << sizeof(students_scores) << endl;

	doSomething(students_scores);

	/*cout << (int)&students_scores << endl;
	cout << (int)&students_scores[0] << endl;
	cout << (int)&students_scores[1] << endl;
	cout << (int)&students_scores[2] << endl;
	cout << (int)&students_scores[3] << endl;
	cout << sizeof(students_scores) << endl;*/

	return 0;
}