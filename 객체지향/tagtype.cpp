#include<stdio.h>
/*
	enum, struct Ű���� ���� �±׸� �ᵵ ���������� ����ü���� �˼�����
	C++�� �±׸� �ϳ��� Ÿ������ ����
*/
int main()
{
	enum origin { EAST, WEST, SOUTH, NORTH };
	
	// enum origin mark = WEST;
	origin mark = WEST;

	printf("%d ����\n", mark);

	struct SHuman
	{
		char name[12];
		int age;
		double height;
	};
	// struct SHuman kim = { "�����",29,181.4 };
	SHuman kim = { "�����",29,181.4 };
	printf("�̸�=%s, ����=%d\n", kim.name, kim.age);
}