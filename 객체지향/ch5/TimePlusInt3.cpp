#include<stdio.h>

class Time
{
private:
	int hour, min, sec;
public:
	Time() {}
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}

	const Time operator+(int s)const {
		Time t = *this;

		t.sec += s;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;
		return t;
	}
};

const Time operator+(int s, const Time& me) {	// (int, Time)순으로 인수를 받아 (Time + int)로 넘김 -> 클래스 멤버 직접 읽지 않음
	return (me + s);
}

int main()
{
	Time now(11, 22, 33);
	now.OutTime();

	now = now + 1;	// operator+ 함수 호출
	now = 1 + now;	// 오버로딩 된 operator+ 함수로 인수의 순서를 바꿔서 함수 호출

	now.OutTime();
}