#include <iostream>

using namespace std;

#define NUM_STUDENTS 10000

void doSomething(int students_scores[]) // ��� �迭�� �ƴϴ�, ��¥ ��ü�� �����ʹ� (������ �����ͷ� �޾ƿ� �ſ��� size�� ������� �ȴ�)
{	// �����Ϸ��� ���������� �긦 �����ͷ� ó���Ѵ�
	// �迭�� ��� ���Ҹ� �����ؼ� �������� ���� �ƴ϶�, parameter�� ������ ��, �迭�� ù��° �ּҰ��� �����ؿ´�
	// �Ѱܹ���, �迭�� ù��° �ּҰ��� �����ϴ� ������ �����̱� ������, �� ��ü�� �ٸ� �ּҰ��� ������
	// => �ּҰ��� �����ϴ�, �ٸ� ����,�� �ּҰ� ��µǴ� ��
	// �׷��� parameter��, �迭�� �����͸� ����Ͽ� ���� �޴� �� ���� �����ϴ�

	cout << (long long)&students_scores << endl;
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	cout << "func " << sizeof(students_scores) << endl;
}

int main()
{
	const int num_students = 20;
	int students_scores[num_students]{ 1, 2, 3, 4, 5 }; // []�� subscript��� �� ������ �ִ� ��?

	// �迭�� ���, �ĺ��ڸ� ��ü�� ���������� �ּҷ� ���Ǳ� ������
	// &���� ĳ���ø� ���൵ �ּҰ� ���´�, ���� &�� �ٿ��� �������
	// �ּҷ� �����͸� �ְ� �޴´�
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