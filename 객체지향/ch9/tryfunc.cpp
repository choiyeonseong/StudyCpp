/*
	try ��� �Լ�
	: �Լ��� �������� �ڵ尡 ��� try��Ͽ� �ۼ��Ǿ� ������ ��ü�� ���� ���� �ʿ���� try ��� ��ü�� �Լ��� ��ü�� ����� �ȴ�.
	�Լ��� ���۰� ���� ǥ���ϴ� {}��ȣ�� ���ְ� try�� catch ����� �Լ��� ��ü�� �� ó�� �ۼ��ϴ� ���̴�.
*/

#include<stdio.h>

void divide(int a, int d)
try {
	if (d == 0) throw "0���δ� ������ �����ϴ�.";
	printf("������ ��� = %d�Դϴ�.\n", a / d);
}
catch (const char* message) {
	puts(message);
}

int main()
{
	divide(10, 0);
}