#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	// ����Ʈ ������
	Human()
	{
		strcpy(name, "�̸�����");
		age = 0;
	}
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
	//Human momo;	// ����Ʈ �����ڷ� ���� ����
	//Human arFriend[3];	// ����Ʈ �����ڰ� ������ ����

	Human arFriend[3] = {
		Human("������",49),
		Human("������",49),
		Human("�ڻ�",49),
	};
	arFriend[2].intro();
}