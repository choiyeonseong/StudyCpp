/*
	���۷����� �̿��� swap�Լ�
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

	cout << "������ �ΰ� �Է�" << endl;
	cin >> a >> b;
	
	reference_swap(a, b);

	cout << a << " " << b;
}