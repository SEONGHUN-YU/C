#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	{
		cout.setf(std::ios::showpos); // setflag
		cout << 108 << endl;
		cout.unsetf(std::ios::showpos);
		cout << 109 << endl;
	}

	{
		//cout.unsetf(std::ios::dec); // 10���� ��带 ���� �ؾ� ��
		//cout.setf(std::ios::hex); // 16�������
		//cout.setf(std::ios::hex, std::ios::basefield); // �ٸ� ������δ� �̷���
		//cout.setf(std::iostream::uppercase); // 16������ ���ĺ��� �빮�ڷ� ������ ����
		
		cout << std::hex << std::uppercase; // �̷��Ե� �ȴ�, iomanip�� ��� ��
		cout << 108 << endl; // �׷� 16������ ����
		cout << 109 << endl;

		cout << std::dec; // �ٽ� 10������ ���ư�
		cout << 110 << endl;
	}

	{
		cout << std::boolalpha; // bool�� ���ڷ� ������ ����
		cout << true << " " << false << endl;
	}

	{
		//cout << std::defaultfloat; �̰� �⺻������ �Ǿ� ����
		//cout << std::fixed; // ��� �ݿø��� �� �ϰ�, �ִ� �״�� �����
		//cout << std::scientific << std::uppercase;
		cout << std::showpoint; // defalut �����ε� .�� ������ �����
		cout << std::setprecision(3) << 123.456 << endl; // �ݿø��ؼ� �����
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
	}

	{
		std::cout << -12345 << endl;
		cout.fill('*'); // ��ĭ�� ä����
		cout << std::setw(10) << -12345 << endl; // ���¸�ŭ �ڷ� ����
		cout << std::setw(10) << std::left << -12345 << endl;
		cout << std::setw(10) << std::right << -12345 << endl;
		cout << std::setw(10) << std::internal << -12345 << endl; // ���¸�ŭ �߰��� ���� ����
	}

	return 0;
}