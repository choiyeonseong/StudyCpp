#include<stdio.h>

int main()
{
	double* ar;
	ar = new double[100];	// ũ�� 100�� �Ǽ��� �迭�� �Ҵ��ϰ�

	ar[50] = 3.14;	// 50��° ��ҿ� 3.14�� �����Ͽ�
	printf("50��° ��� : %.2lf", ar[50]);	// ����϶�

	delete[] ar;
}