/*
	RTTI (RunTime Type Information)
	: �ǽð����� Ÿ�� ������ �˾Ƴ��� ���
*/
#include<stdio.h>
class Parent
{
public:
	virtual void PrintMe() { printf("I am Parent\n"); }
};

class Child :public Parent
{
private:
	int num;
public:
	Child(int anum) :num(anum) {}
	virtual void PrintMe() { printf("I am Child\n"); }
	void PrintNum() { printf("Hello Child = %d\n", num); }
};

void func(Parent* p)
{
	p->PrintMe();
	((Child*)p)->PrintNum();
}

int main()
{
	Parent p;
	Child c(5);

	func(&c);	// �Ѵ� ���� ����
	func(&p);	// printNum�� ������ �� ���
	/*
		�����Լ��� printMe�� ��ü�� ���� Ÿ�Կ� ���� ��Ȯ�ϰ� ȣ�������
		�񰡻��Լ��� printNum�� ���� Ÿ���� �����Ƿ� �׻� Child::PrintNum�� ȣ��ȴ�.
	*/
}