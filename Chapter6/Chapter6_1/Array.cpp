#include <iostream>

using namespace std;

struct Rectangle
{
	int length;
	int width;
};

enum StudentName
{
	JACKJACK, // 0
	DASH, // 1
	VIOLET, // 2
	NUM_STUDENTS // 3
	// 숫자값을 가지기 때문에 index에 넣어줄 수도 있음, 신기하긴 한데... OOP를 노려서?
	// 권장하지는 않는 방법
};

#define NUM_STUDENTS_M 10000 // <- C스타일인데, 권장하지 않는 방법
// c++에는 동적할당이라는 게 있어서 더 좋은 방법이 있는 모양
					
int main()
{
	cout << sizeof(Rectangle) << endl;
	Rectangle rect_arr[10];
	cout << sizeof(rect_arr) << endl;

	// 배열의 길이는 컴파일타임에 고정되어야 한다, 따라서 런타임상수는 못 씀
	// 매크로를 쓰던가(비추천), const 상수를 써야 함
	int students_scores_m[NUM_STUDENTS_M];

	// int my_array[] = {1, 2, 3} 선언과 동시에 초기화 할 때만, 알아서 길이 맞춰서 만들어 줌, 이 경우 [3]
	// c++11부터는 int my_array[]{1, 2, 3}; 으로도 초기화 가능
	int my_array[5] = { 1, 2 }; // 초기화를 덜하면 0으로 알아서 넣어줌

	cout << my_array[JACKJACK] << endl;
	cout << my_array[DASH] << endl;
	cout << my_array[VIOLET] << endl;
	cout << my_array[3] << endl;
	cout << my_array[4] << endl;

	int one_student_score;
	int student_scores[NUM_STUDENTS]; // enum을 이용해서 생성

	cout << sizeof(one_student_score) << endl;
	cout << sizeof(student_scores) << endl;
	
	one_student_score = 100;
	student_scores[JACKJACK] = 100;
	student_scores[DASH] = 80;
	student_scores[VIOLET] = 90;

	// int arr[3];
	// int arr[] = {0, 1, 2};
	// int arr[]{0, 1, 2};

	return 0;
}