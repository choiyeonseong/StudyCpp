#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s("char array");
	string s1("C++ string");

	cout << s.data() << endl;
	cout << s.c_str() << endl;	// string type�� ���ڿ��� charŸ������ �ٲ���

	char str[128];
	strcpy(str, s.c_str());	// string type�� ���ڿ��� charŸ������ �ٲ���
	printf("str = %s\n", str);

	swap(s, s1);
	cout << s << endl;
}