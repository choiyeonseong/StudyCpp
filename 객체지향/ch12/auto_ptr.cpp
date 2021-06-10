/*
	auto_ptr
	: 동적할당 되는 포인터를 래핑하여 객체 파괴시 자동으로 해제
*/
#include<iostream>
#include<memory>
using namespace std;

int main()
{
	auto_ptr<double> rate(new double);

	*rate = 3.1415;
	cout << *rate << endl;
}