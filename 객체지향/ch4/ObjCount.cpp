/*
	Ŭ������ ���õ� ������ �ܺο� ����Ǿ��־� ĸ��ȭ �����̴�.	
	���������� ������ ���������ʾ� �������� �������� �����ϱ� ��ƴ�.
	���� ������ �����Ҽ����� �����ϴ�. �ܺο��� count�� ���� �ٲ㵵 ����� �� ����.
	-> ���õ� ������ Ŭ���� �ȿ� ĸ��ȭ �ؾ��Ѵ�.

*/
#include<stdio.h>


class Simple
{
private:
	int value;
	int count = 0;

public:
	Simple() { count++; }
	~Simple() { count--; }
	void OutCount() {
		printf("���� ��ü ���� = %d\n", count);
	}
};

int main()
{
	Simple s, * ps;
	s.OutCount();
	ps = new Simple;
	ps->OutCount();
	delete ps;
	s.OutCount();
	printf("ũ�� = %d\n", sizeof(s));
}