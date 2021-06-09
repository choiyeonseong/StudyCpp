#include<stdio.h>

class Time
{
public:
	int hour, min, sec;

	void OutTime() {
		printf("현재시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now;
	int Time::* pi;	// time의 정수형 멤버 변수를 가리키는 pi를 선언

	pi = &Time::hour;
	now.*pi = 12;

	pi = &Time::min;	// 멤버 포인터는 변수이므로 실행 중에 가리키는 대상을 바꿀수 있다.
	now.*pi = 34;

	pi = &Time::sec;
	now.*pi = 56;

	now.OutTime();

	/*
		Time형 객체를 가리키는 포인터를 가지고 있다면 .*연산자 대신에 ->*연산자를 사용한다.
		같은 타입의 임의 변수를 가리킨다는 면에서 일반 포인터와 기능이 같되
		범위가 클래스 내부의 멤버로 국한된다는 점이 특수하다
	*/
}