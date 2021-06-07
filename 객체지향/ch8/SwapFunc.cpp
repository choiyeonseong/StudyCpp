#include<stdio.h>

// 타입만 다른 함수
void swap(int& a, int& b)
{
	int t;
	t = a; a = b; b = t;
}

void swap(double& a, double& b)
{
	double t;
	t = a; a = b; b = t;
}

int main()
{
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	swap(a, b);
	swap(c, d);
	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
}