/*
	멤버함수 외부 작성
*/
#include<stdio.h>

struct Human {
	char name[20];
	float height;
	float weight;
	int age;
	char blood;

	void view();	// 원형 선언
};

void Human::view()	// 본체 정의 
{
	printf("나의 이름은 %s이고\n키는 %f이고\n몸무게는 %f이고\n나이는 %d이고\n혈액형은 %c이다.", name, height, weight, age, blood);
}

int main()
{
	Human my = { "최연성",159,2,25,'C' };
	my.view();
		return 0;
}