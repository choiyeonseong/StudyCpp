#include<stdio.h>

struct SHuman
{
	char name[12];
	int age;

	void intro();	// ���� ����
};

void SHuman::intro()	// ��ü �ܺ� ����
{
	printf("�̸� = %s, ���� = %d\n", name, age);
}

int main()
{
	SHuman choi = { "�ֿ���",25 };
	choi.intro();
}