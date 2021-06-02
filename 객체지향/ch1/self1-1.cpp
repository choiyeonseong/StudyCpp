#include<stdio.h>

int main()
{
	double* ar;
	ar = new double[100];	// 크기 100의 실수형 배열을 할당하고

	ar[50] = 3.14;	// 50번째 요소에 3.14를 대입하여
	printf("50번째 요소 : %.2lf", ar[50]);	// 출력하라

	delete[] ar;
}