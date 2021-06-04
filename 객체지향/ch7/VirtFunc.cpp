/*
	�����Լ� virtual
	: �������� ���� Ÿ�Կ� ���� ���� ȣ���� �Լ��� �����ȴ�.
	�����Ͱ� ����Ű�� Ÿ�Կ� ���� ȣ���� �Լ��� �����Ϸ���
	��� �Լ� �տ� virtual Ű���带 �ٿ� �������� �����Ѵ�.
*/
#include<stdio.h>
#include<string.h>

class Human
{
protected:
	char name[12];
	int age;
public:
	Human(const char* aname, int aage)
	{
		strcpy(name, aname);
		age = aage;
	}
	virtual void intro()	// �������� �����ϹǷ� ȣ���Ҷ��� �������� ���� Ÿ���� ���� 
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
	void intro()	// �������̵� 
	{
		printf("%d�й� %s�Դϴ�.\n", stunum, name);
	}
	virtual void study()
	{
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
};

void IntroSomeBody(Human* pH)	// � ��ü�� �ѱ�°��� ���� ȣ��� �Լ��� �����Ǿ� ���� ������ �޶����� -> ������
{
	pH->intro();
}

int main()
{
	Human h("����", 10);
	Student s("���л�", 15, 1234567);

	// 1
	Human* pH;

	pH = &h;
	pH->intro();	// Human::intro����
	pH = &s;

	// pH�� Student ��ü�� ����Ű�� �ִ��� �����Ҷ� Human*�� ��������
	pH->intro();	// ���� Ÿ�� ������ - Human::intro ����
					// ���� Ÿ�� ������(virtual) - Student::intro ����

	// 2
	// � ��ü�� �ѱ�°��� ���� ȣ��� �Լ��� �����Ǿ� ���� ������ �޶����� -> ������
	IntroSomeBody(&h);	// Human::intro ����
	IntroSomeBody(&s);	// Student::intro ����
}