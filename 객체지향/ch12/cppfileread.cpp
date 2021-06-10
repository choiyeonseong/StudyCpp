#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream f;
	char str[128];
	int i;

	f.open("D:\\GitRepository\\StudyCpp\\객체지향\\cpptest.txt");
	if (f.is_open()) {
		f >> str >> i;
		cout << str << i << endl;
		f.close();
	}
	else {
		cout << "파일 열기 실패" << endl;
	}
}