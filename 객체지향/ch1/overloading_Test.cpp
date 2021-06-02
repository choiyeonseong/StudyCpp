#include<iostream>

int func(int a)
{

	return a;
}

int func(int a, int b = 0)	// 디폴트 매개변수 사용하는 경우 : 오버로딩 안됨 -> 모호성
{
	return a + b;
}

int main()
{
	//func(10);
	return 0;
}