#include<iostream>
using namespace std;

class A
{
public:
	virtual void test() { printf("A::test()\n"); }
};

class B : public A
{
public:
	virtual void test() { printf("B::test()\n"); }
	void test2() { printf("B::test2()\n"); }
};

class C :public B
{
public:
	virtual void test() { printf("C::test()\n"); }
	void test2() { printf("C::test2()\n"); }
};

void Globalfunc(A& a)
{
	try {
		C& c = dynamic_cast<C&>(a);	// �θ�ü�� �ڽ��� ����Ű�� ����
		printf("GlobalFunc()\n");
	}
	catch (bad_cast) {
		printf("casting error\n");
	}
}

int main()
{
	A* pa = new C;
	A* paa = new B;
	pa->test();

	B* pb = dynamic_cast<B*>(pa);	// �θ�� �ڽ��� ����ų�� �ִ�
	if (pb) pb->test2();			// C::test() ���

	C* pc = dynamic_cast<C*>(paa);	// �ڽ��� �θ� ����Ű�� ���� - �Ϻ��� ����ȯ�� �̷����������, �ҿ����� ĳ����
	if (pc) pc->test2();			// B::test2() ���
	
	C c;
	Globalfunc(c);		// GlobalFunc()
	B b;
	Globalfunc(b);		// casting error

	return 0;
}