#include<stdio.h>

int main()
{
	int i = 3;
	int& ri = i;	// 레퍼런스(&) : 변수에 대한 별명

	int* pi = &i;

	printf("i = %d, ri = %d, pi = %d\n", i, ri, pi);
	
	ri++;
	
	printf("i = %d, ri = %d, pi = %d\n", i, ri, pi);

	*pi = i + 1;
	
	printf("i = %d, ri = %d, pi = %d\n", i, ri, pi);

	printf("i번지 = %x, ri번지 = %x, pi번지 = %x\n", &i, &ri, &pi);
}