#include<stdio.h>

template <typename T>
T cast(int s)
{
	return T(s);
}

int main()
{
	// ����� �μ� ���� ��� -> ����Ÿ�� ����
	unsigned u = cast<unsigned>(1234);
	double d = cast<double>(5678);

	printf("u = %d\nd = %f\n", u, d);
}