#include<stdio.h>

class Parent
{
public:
	int p;
};

class Child :public Parent
{
public:
	int c;
};

int main()
{
	int Parent :: *pp;	// Parent의 정수형 멤버를 가르킴
	int Child ::* pc;	// Child의 정수형 멤버를 가르킴

	pp = &Parent::p;
	pc = &Child::c;

	pc = &Parent::p;
	pc = &Child::p;

	//pp=&Child::c;
	// 자식은 부모의 멤버를 가지지만 부모가 자식의 멤버를 가지지는 않기 때문이다.
}	