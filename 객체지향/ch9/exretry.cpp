#include<stdio.h>

int main()
{
	int num;

	try {
		printf("1���� 100������ ������ �Է��Ͻÿ� : ");
		scanf("%d", &num);
		if (num < 1 || num>100) throw num;	// Ʋ�� �Է��� ��Ȯ�ϰ� ���������� �ٽ� �Է��ϵ��� ���ư����� ���Ѵ�.
		printf("�Է��� �� = %d\n", num);
	}
	catch (int num) {
		printf("%d�� 1���� 100������ ������ �ƴմϴ�.\n", num);
	}
}