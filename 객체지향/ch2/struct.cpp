/*
	����Լ� �ܺ� �ۼ�
*/
#include<stdio.h>

struct Human {
	char name[20];
	float height;
	float weight;
	int age;
	char blood;

	void view();	// ���� ����
};

void Human::view()	// ��ü ���� 
{
	printf("���� �̸��� %s�̰�\nŰ�� %f�̰�\n�����Դ� %f�̰�\n���̴� %d�̰�\n�������� %c�̴�.", name, height, weight, age, blood);
}

int main()
{
	Human my = { "�ֿ���",159,2,25,'C' };
	my.view();
		return 0;
}