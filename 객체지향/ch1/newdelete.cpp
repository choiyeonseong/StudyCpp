#include<stdio.h>

int main()
{
	int* pi, * pj;

	pi = new int;		// �����ڸ� ȣ���ϴ� ������ �̹Ƿ�
	pj = new int(10);	// �����Ҵ�� ���ÿ� �ʱ�ȭ�� ����

	*pi = 123;
	
	printf("*pi = %d\n", *pi);
	printf("*pj = %d\n", *pj);

	delete pi;		// �Ҹ���
	delete pj;		// �Ҹ���
}