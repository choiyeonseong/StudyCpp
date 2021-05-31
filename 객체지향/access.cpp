/*
	액세스 지정
*/
#include<stdio.h>

struct SHuman{	// 캡슐화, 추상화

private:	// 은닉 // 액세서
	char name[12];
	int age;

public:		// 액세서
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	SHuman kim;
	//kim.age = 286;	// private이라서 액세스 불가
	kim.intro();
}