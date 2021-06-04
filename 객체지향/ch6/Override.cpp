#include<stdio.h>
#include<string.h>

class Human
{
protected:	// 접근 지정자
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro()
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
	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
	void intro()	// 오버라이딩	// 부모 클래스의 함수를 재정의
	{
		printf("%d학번 %s입니다.\n", stunum, name);
	}
};

int main()
{
	Human kim("김상형", 29);
	kim.intro();
	Student han("김한결", 15, 123456);
	han.intro();	// 함수이름이 중복이면 지역이 우선, 부모의 함수는 숨겨지고 학생객체에 대한 함수 호출
	han.Human::intro();	// 범위 지정 연산자를 이용해서 숨겨진 부모 클래스의 intro 함수를 출력
}