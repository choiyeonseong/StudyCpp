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
	int Parent :: *pp;	// Parent�� ������ ����� ����Ŵ
	int Child ::* pc;	// Child�� ������ ����� ����Ŵ

	pp = &Parent::p;
	pc = &Child::c;

	pc = &Parent::p;
	pc = &Child::p;

	//pp=&Child::c;
	// �ڽ��� �θ��� ����� �������� �θ� �ڽ��� ����� �������� �ʱ� �����̴�.
}	