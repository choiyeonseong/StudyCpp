#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	// 생성자 : 자료형이 없고 리턴값이 없음, 클래스와 이름이 같음
	Human(const char* aname, int aage)
	{
		strcpy(name, aname);
		age = aage;
	}
	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human kim("김상형", 29);
	kim.intro();
}