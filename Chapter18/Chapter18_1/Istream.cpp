#include <iostream>
#include <string>
#include <iomanip> // input/output manipulators

using namespace std;

int main()
{
	/*{
		cout << "Enter a number" << endl;
		int i;
		cin >> i;
		cout << i << endl;
	}*/


	// �⺻������ stream�� buffer�� �ӽ������� ����� �͵��� �Ϻξ� �������� ����̴�
	/*{
		//char buf[5];
		//cin >> setw(5) >> buf; // setw(10) �ִ� 10���ڸ� �޵��� ������ ����
		//cout << buf << endl;
		//cin >> setw(5) >> buf; // null character �ڸ� ������ 4���ڸ� ������
		//cout << buf << endl;
		//cin >> setw(5) >> buf;
		//cout << buf << endl;

		//int i;
		//float f;
		//cin >> i >> f; // " "�� �����ڰ� ��, �� ���� ���� ���� �ʱ�ȭ �ϱ⿡�� ����
		//cout << i << " " << f << endl;

		char buf[100];
		// �׳� cin�� ���� " "�� ���õǰ� �ٿ���, ���������� �׻� ���� ���� �ƴ�
		cin.getline(buf, 100); // .get()�� ���� " "�� �Է¹��� �� ����, .getline()�� ����
		cout << cin.gcount() << " " << buf << endl; // ���������� buffer�� ������ ���� ���� ����
		cin.get(buf, 100);
		cout << cin.gcount() << " " << buf << endl; // .getline()�� �ϸ� lineä�� �������� ������ buffer�� ������
		// .getline()�� '\n'���� ���� �о�ͼ� �����Ѵٴ� �� ��
		// .get()�� '\0'�� ���� �� �ϴ� �� �� (��Ȯ�� �𸣰���)
	}*/

	/*{
		string buf;
		getline(cin, buf);
		cout << cin.gcount() << " " << buf << endl; // �׳� getline()�� �� ���� cin.gcount()�� ������ ������
	}*/

	{
		char buf[1024];
		//cin.ignore(2); // 2���ڸ�ŭ �����Ѵ�
		cout << (char)cin.peek() << endl; // buffer�� �鿩�ٺ��⸸ �ϰ� ������ ���� ���������� ����, ������ �� ���ڰ� ���� Ȯ���ϴ� ������ ��
		cin >> buf;
		cout << buf << endl;
		//cin.unget(); // �������� ������ �� �ٽ� buffer�� �־����
		cin.putback('A'); // ���ϴ� ���ڸ� buffer�� �־����
		cin >> buf;
		cout << buf << endl;
	}

	return 0;
}