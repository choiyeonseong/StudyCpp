#include<stdio.h>

int main()
{
	int* ar;

	ar = new int[5];	// (int*)malloc(sizeof(int)*5) : C
	
	for (int i = 0; i < 5; i++) {
		ar[i] = i;
	}

	for (int i = 0; i < 5; i++){
		printf("%d¹øÂ° = %d\n", i, ar[i]);
	}
	
	delete[] ar;
}