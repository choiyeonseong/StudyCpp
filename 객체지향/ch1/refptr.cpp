#include<stdio.h>
#include<malloc.h>
#include<string.h>

/*
	���۷����� �Ű������� �޴� �Լ���
	ȣ����� ������ ��ȣ��� ���� �Լ� ������ ���߸� ����ȣ������ ��ȣ������ �˼�����
	=>>���۷����� ����ϸ� ���ϱ���~ ���ĸŰ������� ����Ҷ� �ɷ� ����
*/
void InputNameByRef(char*& Name)	// �������� ���۷���
{
	Name = (char*)malloc(32);
	strcpy(Name, "kim sang hyung");
}

int main()
{
	/*
	char* Name;

	InputNameByRef(Name);
	printf("�̸��� %s�Դϴ�.\n", Name);
	free(Name);
	*/

	int a = 10;
	int& ra = a;
	int* pa = &ra;
	printf("%p %p %p", &a, &ra, pa);	// ��� �����ϰ� ���� a�� ����Ű�� ����
}

/*
// ���۷����� ������� �ʴ� ���
void InputName(char* *Name)	// ���������� ����ؾ� ��
{
	*Name = (char*)malloc(32);
	strcpy(*Name, "kim sang hyung");
}

int main()
{
	char* Name = NULL;

	InputName(&Name);
	printf("�̸��� %s�Դϴ�.\n", Name);
	free(Name);
}
*/
