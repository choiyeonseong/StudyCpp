/*
	함수 템플릿 : 함수를 만드는 형틀
	자료형을 일반화시킴
	비슷한 모양의 함수가 여러개 필요하다면
	일일이 함수를 정의하는 것보다 템플릿을 먼저 만들어 두고 
	템플릿으로 부터 필요한 함수를 찍어내는것이 효율적

	함수 템플릿 인수 목록에 두개이상의 타입 사용 가능
*/
#include<stdio.h>

template <typename T> void swap(T& a, T& b);	// 함수 템플릿 정의는 함수 호출보다 먼저 와야한다.

int main()
{
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	char e = 'e', f = 'f';

	swap(a, b);
	swap(c, d);
	swap(e, f);

	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
	printf("e = %c, f = %c\n", e, f);
}

template <typename T>	// 임의의 타입
void swap(T& a, T& b)
{
	T t;
	t = a; a = b; b = t;
}