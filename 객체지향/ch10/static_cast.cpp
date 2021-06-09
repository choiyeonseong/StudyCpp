#include<stdio.h>

int main()
{
	const char* str = "korea";
	int* pi;
	double d = 123.456;
	int i;
	int ary[] = { 1,2,3,4,5 };
	int* ptr = static_cast<int*>(ary);	// 가능 - 동일한 타입인 경우 가능
	char aary[] = { 'a','b' };


	i = static_cast<int>(d);		// 가능
	//pi = static_cast<int*>(str);	// 에러 - 포인터 타입을 다른 것으로 변경하는 것은 금지
	pi = (int*)str;					// 가능
}