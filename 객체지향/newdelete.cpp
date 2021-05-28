#include<stdio.h>

int main()
{
	int* pi, * pj;

	pi = new int;		// 생성자를 호출하는 연산자 이므로
	pj = new int(10);	// 동적할당과 동시에 초기화가 가능

	*pi = 123;
	
	printf("*pi = %d\n", *pi);
	printf("*pj = %d\n", *pj);

	delete pi;		// 소멸자
	delete pj;		// 소멸자
}