#include<iostream>

int func(int a)
{

	return a;
}

int func(int a, int b = 0)	// ����Ʈ �Ű����� ����ϴ� ��� : �����ε� �ȵ� -> ��ȣ��
{
	return a + b;
}

int main()
{
	//func(10);
	return 0;
}