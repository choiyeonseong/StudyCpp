/*
	멤버 포인터 변수
	: 특정 클래스에 속한 특정 타입의 멤버를 가리키는 포인터
	클래스 내의 한 지점을 가리킨다
*/
#include<stdio.h>

class MyClass
{
public:
	int i, j;
	double d;
};

int main() 
{
	MyClass C;
	int MyClass::* pi;	// 멤버 포인터 변수
	double MyClass::* pd;
	int num;

	pi = &MyClass::i;	// 멤포인터 변수에 멤버 변수의 번지를 대입하는것은 가리킬 대상을 알려줄뿐 객체의 멤버를 직접 가리키는것은 아니다
	pi = &MyClass::j;	
	pd = &MyClass::d;
	//pd = &MyClass::i;	// 소속은 같지만 타입이 다름
	//pi = &MyClass::d;
	//pi = &num;		// 타입은 같지만 클래스 소속이 아닌 지역변수임
}