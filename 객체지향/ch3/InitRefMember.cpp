/*
	���۷����� �ٸ� ������ ���� �����̸� �ʱ�ȭ ���Ŀ��� ����� �����Ҽ�����.
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