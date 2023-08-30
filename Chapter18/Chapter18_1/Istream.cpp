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


	// 기본적으로 stream은 buffer에 임시적으로 저장된 것들을 일부씩 꺼내오는 방식이다
	/*{
		//char buf[5];
		//cin >> setw(5) >> buf; // setw(10) 최대 10글자만 받도록 방지를 해줌
		//cout << buf << endl;
		//cin >> setw(5) >> buf; // null character 자리 때문에 4글자만 가져옴
		//cout << buf << endl;
		//cin >> setw(5) >> buf;
		//cout << buf << endl;

		//int i;
		//float f;
		//cin >> i >> f; // " "가 구분자가 됨, 한 번에 여러 변수 초기화 하기에는 좋음
		//cout << i << " " << f << endl;

		char buf[100];
		// 그냥 cin을 쓰면 " "는 무시되고 붙여짐, 불편하지만 항상 나쁜 것은 아님
		cin.getline(buf, 100); // .get()을 쓰면 " "도 입력받을 수 있음, .getline()도 있음
		cout << cin.gcount() << " " << buf << endl; // 마찬가지로 buffer에 내용이 아직 남아 있음
		cin.get(buf, 100);
		cout << cin.gcount() << " " << buf << endl; // .getline()을 하면 line채로 가져오기 때문에 buffer가 비어버림
		// .getline()은 '\n'까지 같이 읽어와서 저장한다는 듯 함
		// .get()은 '\0'은 저장 안 하는 듯 함 (정확히 모르겠음)
	}*/

	/*{
		string buf;
		getline(cin, buf);
		cout << cin.gcount() << " " << buf << endl; // 그냥 getline()을 할 때는 cin.gcount()랑 관련이 없어짐
	}*/

	{
		char buf[1024];
		//cin.ignore(2); // 2글자만큼 무시한다
		cout << (char)cin.peek() << endl; // buffer를 들여다보기만 하고 실제로 값을 가져오지는 않음, 다음에 올 글자가 뭔지 확인하는 정도로 씀
		cin >> buf;
		cout << buf << endl;
		//cin.unget(); // 마지막에 가져온 걸 다시 buffer에 넣어버림
		cin.putback('A'); // 원하는 글자를 buffer에 넣어버림
		cin >> buf;
		cout << buf << endl;
	}

	return 0;
}