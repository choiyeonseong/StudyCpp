#include<stdio.h>

int main()
{
	int i = 3;
	int& ri = i;	// ���۷���(&) : ������ ���� ����

	int* pi = &i;

	printf("i = %d, ri = %d, pi = %d\n", i, ri, pi);
	
	ri++;
	
	printf("i = %d, ri = %d, pi = %d\n", i, ri, pi);

	*pi = i + 1;
	
	printf("i = %d, ri = %d, pi = %d\n", i, ri, pi);

	printf("i���� = %x, ri���� = %x, pi���� = %x\n", &i, &ri, &pi);
}