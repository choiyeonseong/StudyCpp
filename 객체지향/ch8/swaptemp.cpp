/*
	�Լ� ���ø� : �Լ��� ����� ��Ʋ
	�ڷ����� �Ϲ�ȭ��Ŵ
	����� ����� �Լ��� ������ �ʿ��ϴٸ�
	������ �Լ��� �����ϴ� �ͺ��� ���ø��� ���� ����� �ΰ� 
	���ø����� ���� �ʿ��� �Լ��� ���°��� ȿ����

	�Լ� ���ø� �μ� ��Ͽ� �ΰ��̻��� Ÿ�� ��� ����
*/
#include<stdio.h>

template <typename T> void swap(T& a, T& b);	// �Լ� ���ø� ���Ǵ� �Լ� ȣ�⺸�� ���� �;��Ѵ�.

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

template <typename T>	// ������ Ÿ��
void swap(T& a, T& b)
{
	T t;
	t = a; a = b; b = t;
}