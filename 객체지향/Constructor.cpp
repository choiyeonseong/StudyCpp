#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	// ������ : �ڷ����� ���� ���ϰ��� ����, Ŭ������ �̸��� ����
	Human(const char* aname, int aage)
	{
		strcpy(name, aname);
		age = aage;
	}
	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	Human kim("�����", 29);
	kim.intro();
}