#include<stdio.h>
/*
	enum, struct 키워드 없이 태그만 써도 열거형인지 구조체인지 알수있음
	C++은 태그를 하나의 타입으로 인정
*/
int main()
{
	enum origin { EAST, WEST, SOUTH, NORTH };
	
	// enum origin mark = WEST;
	origin mark = WEST;

	printf("%d 방향\n", mark);

	struct SHuman
	{
		char name[12];
		int age;
		double height;
	};
	// struct SHuman kim = { "김상형",29,181.4 };
	SHuman kim = { "김상형",29,181.4 };
	printf("이름=%s, 나이=%d\n", kim.name, kim.age);
}