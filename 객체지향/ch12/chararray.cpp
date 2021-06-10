#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s("char array");
	string s1("C++ string");

	cout << s.data() << endl;
	cout << s.c_str() << endl;	// string type의 문자열을 char타입으로 바꿔줌

	char str[128];
	strcpy(str, s.c_str());	// string type의 문자열을 char타입으로 바꿔줌
	printf("str = %s\n", str);

	swap(s, s1);
	cout << s << endl;
}