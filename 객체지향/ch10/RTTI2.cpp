#include<stdio.h>
#include<typeinfo>

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
// 실행중에 타입을 조사하여 적용하므로 항상 안전하다.
void func(Parent* p)
{
	p->PrintMe();
	if (typeid(*p) == typeid(Child)) {	// p와 child의 타입 정보를 ==연산자로 비교
		((Child*)p)->PrintNum();
	}
	else {
		puts("이 객체는 num을 가지고 있지 않습니다.");
	}
}

int main()
{
	Parent p;
	Child c(5);

	func(&c);
	func(&p);
}