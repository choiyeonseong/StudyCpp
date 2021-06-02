#include<stdio.h>

struct SHuman
{
	char name[12];
	int age;

	void intro();	// 원형 선언
};

void SHuman::intro()	// 본체 외부 정의
{
	printf("이름 = %s, 나이 = %d\n", name, age);
}

int main()
{
	SHuman choi = { "최연성",25 };
	choi.intro();
}