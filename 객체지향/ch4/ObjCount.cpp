/*
	클래스와 관련된 정보가 외부에 선언되어있어 캡슐화 위반이다.	
	전역변수가 없으면 동작하지않아 독립성이 떨어지며 재사용하기 어렵다.
	전역 변수는 은폐할수없어 위험하다. 외부에서 count를 뭘로 바꿔도 방어할 수 없다.
	-> 관련된 정보는 클래스 안에 캡슐화 해야한다.

*/
#include<stdio.h>


class Simple
{
private:
	int value;
	int count = 0;

public:
	Simple() { count++; }
	~Simple() { count--; }
	void OutCount() {
		printf("현재 객체 개수 = %d\n", count);
	}
};

int main()
{
	Simple s, * ps;
	s.OutCount();
	ps = new Simple;
	ps->OutCount();
	delete ps;
	s.OutCount();
	printf("크기 = %d\n", sizeof(s));
}