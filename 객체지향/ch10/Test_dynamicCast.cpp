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
		C& c = dynamic_cast<C&>(a);	// 부모객체를 자식이 가리키는 형태
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

	B* pb = dynamic_cast<B*>(pa);	// 부모는 자식을 가리킬수 있다
	if (pb) pb->test2();			// C::test() 출력

	C* pc = dynamic_cast<C*>(paa);	// 자식이 부모를 가르키는 형태 - 완벽한 형변환이 이루어지지않음, 불완전한 캐스팅
	if (pc) pc->test2();			// B::test2() 출력
	
	C c;
	Globalfunc(c);		// GlobalFunc()
	B b;
	Globalfunc(b);		// casting error

	return 0;
}