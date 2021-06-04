#include<iostream>

using namespace std;

class A
{
public:
	void AFunc()
	{
		cout << "A::AFunc()" << endl;
	}
};

class B:public A
{
public:
	void BFunc()
	{
		cout << "B::BFunc()" << endl;
	}
};

class C :public B
{
public:
	void CFunc()
	{
		cout << "C::CFunc()" << endl;
	}
};

int main()
{
	// 포인터 타입에 따라 실질적으로 사용할 수 있는 범위가 정해짐
	// 부모 클래스는 자식 클래스를 가르킬 수 있음
	// 자식은 부모를 가르킬 수 없다
	// C* pcc = new A;	// 불가능

	A* pa = new C;	// 기초 클래스 타입의 포인터가 파생객체를 가리키고 있다.
	pa->AFunc();

	B* pb = new C;
	pb->AFunc();
	pb->BFunc();

	C* pc = new C;
	pc->AFunc();
	pc->BFunc();
	pc->CFunc();

	return 0;
}