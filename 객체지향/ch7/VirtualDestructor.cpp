/*
	부모가 할당한 배열은 잘 해체 되지만 자식이 할당한 배열은 해제되지 않아 메모리 누수가 발생한다.
	파괴자를 가상으로 선언하면 동적 결합되어 메모리 누수를 막을수 있다.
	-> 파괴자는 항상 가상으로 선언되어야한다.
*/

#include<stdio.h>

class Base
{
private:
	char* B_buf;
public:
	Base() { B_buf = new char[10]; puts("Base 생성"); }
	virtual ~Base() { delete[] B_buf; puts("Base 파괴"); }
};

class Derived :public Base
{
private:
	int* D_buf;
public:
	Derived() { D_buf = new int[32]; puts("Derived 생성"); }
	virtual ~Derived() { delete[] D_buf; puts("Derived 파괴"); }
};

int main()
{
	Base* pB;

	pB = new Derived;

	delete pB;	
}