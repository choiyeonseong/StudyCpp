#include<stdio.h>

int ar[] = { 1,2,3,4,5 };

int& GetAr(int i)
{
	return ar[i];
}

int main()
{
	//int& ra = 10;	// 상수에는 별명을 줄수 없음
	GetAr(3) = 6;	// 함수 호출문에 값을 대입하는것이 가능 -> 리턴되는 대상이 좌변값(lvalue)이라서
	printf("ar[3] = %d\n", ar[3]);
}