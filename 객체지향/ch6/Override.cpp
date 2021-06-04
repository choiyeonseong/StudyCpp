#include<stdio.h>
#include<string.h>

class Human
{
protected:	// ���� ������
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

class Student :public Human
{
protected:
	int stunum;
public:
	Student(const char* aname, int aage, int astunum) :Human(aname, aage)
	{
		stunum = astunum;
	}
	void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
	void intro()	// �������̵�	// �θ� Ŭ������ �Լ��� ������
	{
		printf("%d�й� %s�Դϴ�.\n", stunum, name);
	}
};

int main()
{
	Human kim("�����", 29);
	kim.intro();
	Student han("���Ѱ�", 15, 123456);
	han.intro();	// �Լ��̸��� �ߺ��̸� ������ �켱, �θ��� �Լ��� �������� �л���ü�� ���� �Լ� ȣ��
	han.Human::intro();	// ���� ���� �����ڸ� �̿��ؼ� ������ �θ� Ŭ������ intro �Լ��� ���
}