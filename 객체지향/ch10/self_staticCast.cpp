#include<iostream>
using namespace std;

int main()
{
	int sum = 124;
	int num = 5;
	
	double dsum = static_cast<double>(sum);
	double dnum = static_cast<double>(num);

	cout << (dsum/dnum) << endl;
}