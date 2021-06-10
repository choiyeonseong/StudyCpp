#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name, addr;

	cout << "이름을 입력하시오 : ";
	cin >> name;
	cout << "입력한 이름은 " << name << "입니다." << endl;
	cin.ignore();	// cin은 입력 후 개행 코드를 버퍼에 남겨서 새로운 문자열을 받으려면 버퍼를 비워야함
	cout << "주소를 입력하시오 : ";
	getline(cin, addr);	// 문자열 입력
	cout << "입력한 주소는 " << addr << "입니다." << endl;
}