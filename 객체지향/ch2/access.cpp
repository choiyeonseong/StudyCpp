/*
	�׼��� ����
*/
#include<stdio.h>

struct SHuman{	// ĸ��ȭ, �߻�ȭ

private:	// ���� // �׼���
	char name[12];
	int age;

public:		// �׼���
	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	SHuman kim;
	//kim.age = 286;	// private�̶� �׼��� �Ұ�
	kim.intro();
}