/*
	가상함수 virtual
	: 포인터의 동적 타입에 따라 실제 호출할 함수가 결정된다.
	포인터가 가리키는 타입에 따라 호출할 함수를 결정하려면
	멤버 함수 앞에 virtual 키워드를 붙여 가상으로 선언한다.
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
	virtual void intro()	// 가상으로 선언하므로 호출할때는 포인터의 동적 타입을 따름 
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
	virtual void study()
	{
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};

void IntroSomeBody(Human* pH)	// 어떤 객체를 넘기는가에 따라 호출될 함수가 결정되어 실제 동작이 달라진다 -> 다형성
{
	pH->intro();
}

int main()
{
	Human h("김사람", 10);
	Student s("이학생", 15, 1234567);

	// 1
	Human* pH;

	pH = &h;
	pH->intro();	// Human::intro실행
	pH = &s;

	// pH가 Student 객체를 가리키고 있더라도 선언할때 Human*로 선언했음
	pH->intro();	// 정적 타입 따를때 - Human::intro 실행
					// 동적 타입 따를때(virtual) - Student::intro 실행

	// 2
	// 어떤 객체를 넘기는가에 따라 호출될 함수가 결정되어 실제 동작이 달라진다 -> 다형성
	IntroSomeBody(&h);	// Human::intro 실행
	IntroSomeBody(&s);	// Student::intro 실행
}