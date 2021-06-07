#include<stdio.h>

template<typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

int main()
{
	int a = max(1, 2);
	double b = max<double>(1.1, 2.2);
	//int c = max(2, 3.14);			// 두 인수 타입이 달라 템플릿의 구조와 맞지 않다
	int c = max<double>(2, 3.14);	// 명시적 타입 지정

	printf("c = %d\n", c);
}