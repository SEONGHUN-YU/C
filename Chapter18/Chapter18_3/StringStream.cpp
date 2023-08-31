#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	{
		stringstream os;

		os << "Hello, World!"; // << : insertion operator, >> : extraction operator
		os << "Hello, World!2" << endl; // endl�� stringstream�� ����
		//os.str("Hello, World!\n"); // �̷��� ���� ���� ����, buffer�� �־��� ��, '\n'�� ���Խ�ų �� ����
		// os.str()�� ���� buffer�� �ִ� ������ ��°�� �ٲ����

		string str;
		//os >> str; // buffer�� ����ִ� �� str�� �־��ְ� ����, " "�� ������ �߷�����
		str = os.str(); // buffer�� ����ִ� �� ��°�� ������
		cout << str << endl;
		cout << os.str() << endl;
	}

	{
		stringstream os;
		//os << "12345 67.89";
		/*int i = 12345;
		double d = 67.89;
		// ���ڸ� �־ << ���ڷ� �޴� >> �͵� �������� �� �ǰ�
		os << i << " " << d;*/ // stream�� ���������� " "�� �����ڷ� ����
		
		// ���ڸ� �־ << ���ڷ� �޴� >> �͵� ���������� �� �۵��Ѵ�
		os << "12345 67.89";
		//int i2;
		//double d2;
		//os >> i2 >> d2; 
		//cout << i2 << "|" << d2 << endl;

		//os.str(""); // �̷��� �ϸ� stream�� ������� �� �ִ�
		//os.str(string()); // �̷��� ����� ����� �ִ�
		os.clear(); // �̷� �͵� �ִµ� ���� �̻��ϴ�
		os << "Hello";
		cout << os.str() << endl;

		/*string str1;
		string str2;
		os >> str1 >> str2;
		cout << str1 << "|" << str2 << endl;*/
	}

	return 0;
}