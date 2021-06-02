#include<stdio.h>

class Time;	// 클래스를 전방 선언 -> 두 클래스가 서로 먼저 알아야 하는 상황

class Date
{
private:
	int year, month, day;

public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutToday(Time& t);	// 함수 내에서 Time 클래스를 사용하기 위해 먼저 선언
};

class Time
{
	friend void Date::OutToday(Time& t);	// 멤버 함수에게만 프렌드 지정

private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
};

void Date::OutToday(Time& t) {	// Time 클래스를 사용하기 위해 클래스를 먼저 선언하고 함수를 정의
	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
		year, month, day, t.hour, t.min, t.sec);
}

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	d.OutToday(t);
}