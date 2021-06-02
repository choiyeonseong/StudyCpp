/*
	함수 오버로딩(overloading)
	중복 정의
*/

#include<stdio.h>

int Add(int a, int b);	// 일반 변수
int Add(const int a, const int b);	// 상수 -> 형태가 달라서 오버로딩 가능
int Add(int a, int b, int c);
double Add(double a, double b);

int main() 
{
	printf("1 + 2 = %d\n", Add(1, 2));
	printf("3 + 4 + 5 = %d\n", Add(3, 4,5));
	printf("1.414 + 2.54 = %f\n", Add(1.414, 2.54));
}

int Add(int a, int b)
{
	return a + b;
}

int Add(int a, int b, int c)
{
	return a + b + c;
}

double Add(double a, double b)
{
	return a + b;
}