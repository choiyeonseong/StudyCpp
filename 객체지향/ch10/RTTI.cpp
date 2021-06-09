/*
	RTTI (RunTime Type Information)
	: 실시간으로 타입 정보를 알아내는 기술
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

	func(&c);	// 둘다 정상 동작
	func(&p);	// printNum이 엉뚱한 값 출력
	/*
		가상함수인 printMe는 객체의 동적 타입에 따라 정확하게 호출되지만
		비가상함수인 printNum은 정적 타입을 따르므로 항상 Child::PrintNum이 호출된다.
	*/
}