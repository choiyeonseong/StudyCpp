#include<stdio.h>

class Parent {};
class Child:public Parent{};

int main()
{
	Parent P, * pP;
	Child C, * pC;
	int i = 1234;

	pP = static_cast<Parent*>(&C);	// 가능 - 업캐스팅(상속 계층의 위쪽으로 변환)
	pC = static_cast<Child*>(&P);	// 가능하지만 위험 - 다운캐스팅(부모 객체의 번지를 자식 타입의 포인터로 바꿈)
	//pP = static_cast<Parent*>(&i);	// 에러 - 정수형 포인터를 아무런 관련없는 클래스형 포인터로 변환하므로 금지
	//pC = static_cast<Child*>(&i);	// 에러 - 정수형 변수가 class의 멤버를 가지고 있지 않아 변환할 필요조차 없음
}