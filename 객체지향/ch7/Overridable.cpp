/*
	동적 결합은 포인터를 통해 멤버 함수를 호출할때만 적용
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
	void eat()
	{
		puts("냠냠냠");
	}
	virtual void intro()	// 가상으로 선언
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
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
	void intro()	// 오버라이딩
	{
		printf("%d학번 %s입니다.\n", stunum, name);
	}
};

int main()
{
	Human h("김사람", 10);
	Student s("이학생", 15, 1234567);
	Human* pH;

	// 동적 결합
	pH = &h;
	pH->intro();
	pH->eat();	// H::eat()

	pH = &s;
	pH->intro();
	pH->eat();	// H::eat()

	// 정적 결합
	h.intro();
	s.intro();
}