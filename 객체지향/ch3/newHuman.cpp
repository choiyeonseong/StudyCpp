#include<stdio.h>
#include<string.h>

class Human
{
private:
	char* pname;
	int age;

public:
	// 생성자
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
		printf("==<%s> 객체 생성 ==\n", pname);
	}
	// 파괴자
	~Human() {
		printf("==<%s> 객체 파괴 ==\n", pname);
		delete[] pname;
	}

	void intro(){
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

int main()
{
	Human boy("김수한무거북이와두루미", 12);
	boy.intro();

	Human* leo;
	leo = new Human("레오나르도 디카프리오", 40);
	leo->intro();
	delete leo;
}