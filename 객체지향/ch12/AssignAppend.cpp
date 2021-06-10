#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1("1234567890");
	string s2("abcdefghijklmnopqrstuvwxyz");
	string s3;

	s3.assign(s1, 3, 4);	// 3위치에서 4개만큼 대입
	cout << s3 << endl;
	s3.append(s2, 10, 7);	// 10위치에서 7개만큼 연결
	cout << s3 << endl;
}