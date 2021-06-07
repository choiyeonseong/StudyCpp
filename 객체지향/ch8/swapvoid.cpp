#include<stdio.h>
#include<malloc.h>
#include<memory.h>

void swap(void* a, void* b, size_t len)	// size_t는 이론상 가장 큰 사이즈를 담을 수 있는 "unsigned 데이터 타입"(overflow 방지)
{
	void* t;
	t = malloc(len);	// 타입을 모르기때문에 임시변수를 동적할당
	memcpy(t, a, len);	// 메모리의 값을 복사하는 기능
	memcpy(a, b, len);
	memcpy(b, t, len);
	free(t);
}

int main()
{
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	swap(&a, &b, sizeof(int));
	swap(&a, &b, sizeof(int));
	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
}