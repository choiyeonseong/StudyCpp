#include<stdio.h>

class Time
{
	friend const Time operator+(int s, const Time& me);	// 외부 함수에 대해 friend로 지정
private:
	int hour, min, sec;
public:
	Time(){}
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}
};

const Time operator+(int s, const Time& me) {	// 정수에 시간객체를 더한다.
	Time t = me;

	t.sec += s;
	
	t.min += t.sec / 60;
	t.sec %= 60;
	t.hour += t.min / 60;
	t.min %= 60;
	return t;
}

int main()
{
	Time now(11, 22, 33);
	now.OutTime();
	now = 1 + now;
	now.OutTime();
}