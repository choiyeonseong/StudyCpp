/*
	레퍼런스는 다른 변수에 대한 별명이며 초기화 이후에는 대상을 변경할수없다.
*/
#include<stdio.h>

class Some
{
public:
	int& total;
	int n1, n2;
	Some(int& atotal, int an1, int an2) :total(atotal),n1(an1),n2(an2) {}
	void OutTotal() { printf("%d\n", total); }
};

int main()
{
	int value = 8;
	Some S(value,1,2);
	S.OutTotal();
}