#include<iostream>
using namespace std;

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	cout << Add(10, 20) << endl;
	cout << Add(3.14, 2.5) << endl;

	return 0;
}