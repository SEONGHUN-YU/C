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
	// ���ڰ��� ������ ������ index�� �־��� ���� ����, �ű��ϱ� �ѵ�... OOP�� �����?
	// ���������� �ʴ� ���
};

#define NUM_STUDENTS_M 10000 // <- C��Ÿ���ε�, �������� �ʴ� ���
// c++���� �����Ҵ��̶�� �� �־ �� ���� ����� �ִ� ���
					
int main()
{
	cout << sizeof(Rectangle) << endl;
	Rectangle rect_arr[10];
	cout << sizeof(rect_arr) << endl;

	// �迭�� ���̴� ������Ÿ�ӿ� �����Ǿ�� �Ѵ�, ���� ��Ÿ�ӻ���� �� ��
	// ��ũ�θ� ������(����õ), const ����� ��� ��
	int students_scores_m[NUM_STUDENTS_M];

	// int my_array[] = {1, 2, 3} ����� ���ÿ� �ʱ�ȭ �� ����, �˾Ƽ� ���� ���缭 ����� ��, �� ��� [3]
	// c++11���ʹ� int my_array[]{1, 2, 3}; ���ε� �ʱ�ȭ ����
	int my_array[5] = { 1, 2 }; // �ʱ�ȭ�� ���ϸ� 0���� �˾Ƽ� �־���

	cout << my_array[JACKJACK] << endl;
	cout << my_array[DASH] << endl;
	cout << my_array[VIOLET] << endl;
	cout << my_array[3] << endl;
	cout << my_array[4] << endl;

	int one_student_score;
	int student_scores[NUM_STUDENTS]; // enum�� �̿��ؼ� ����

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