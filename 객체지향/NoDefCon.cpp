#include<stdio.h>
#include<string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	// 디폴트 생성자
	Human()
	{
		strcpy(name, "이름없음");
		age = 0;
	}
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
	//Human momo;	// 디폴트 생성자로 생성 가능
	//Human arFriend[3];	// 디폴트 생성자가 없으면 에러

	Human arFriend[3] = {
		Human("문동욱",49),
		Human("김유진",49),
		Human("박상막",49),
	};
	arFriend[2].intro();
}