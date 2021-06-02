/*
	레퍼런스를 이용한 swap함수
*/

#include<iostream>

using namespace std;

void reference_swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a, b;

	cout << "정수값 두개 입력" << endl;
	cin >> a >> b;
	
	reference_swap(a, b);

	cout << a << " " << b;
}