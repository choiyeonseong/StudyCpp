#include<stdio.h>

template <typename T>
T cast(int s)
{
	return T(s);
}

int main()
{
	// 명시적 인수 지정 기법 -> 리턴타입 결정
	unsigned u = cast<unsigned>(1234);
	double d = cast<double>(5678);

	printf("u = %d\nd = %f\n", u, d);
}