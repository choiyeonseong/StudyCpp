#include<stdio.h>

int ar[] = { 1,2,3,4,5 };

int& GetAr(int i)
{
	return ar[i];
}

int main()
{
	//int& ra = 10;	// ������� ������ �ټ� ����
	GetAr(3) = 6;	// �Լ� ȣ�⹮�� ���� �����ϴ°��� ���� -> ���ϵǴ� ����� �º���(lvalue)�̶�
	printf("ar[3] = %d\n", ar[3]);
}