#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1("test");
	string s2(s1);	// s1복사
	string s3;
	string s4(10, 'S');	// s를 10개 반복해서 만들어라
	string s5("very nice day", 8);	// 8개의 문자만 초기화
	const char* str = "abcdefghijklmnopqrstuvwxyz";	// 포인터로 가르키고 있어서 변경이 안되기때문에 const를 붙여야함
	string s6(str + 5, str + 10);	// begin ~ end

	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;
	cout << "s3=" << s3 << endl;
	cout << "s4=" << s4 << endl;
	cout << "s5=" << s5 << endl;
	cout << "s6=" << s6 << endl;
}