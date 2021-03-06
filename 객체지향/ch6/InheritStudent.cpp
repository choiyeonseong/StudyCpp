#include<stdio.h>
#include<string.h>

class Human	// 부모 클래스
{
private:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

class Student :public Human	// 자식 클래스
{
private:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) :Human(aname, aage) {	// 부모클래스의 생성자를 호출하면서 초기화가 이루어지고
		stunum = astunum;	// 자식클래스의 생성자는 자기의 멤버변수만 초기화 시킨다
	}
	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};

int main()
{
	Human kim("김상형", 29);
	kim.intro();
	Student han("김한결", 15, 123456);
	han.intro();
	han.study();
}