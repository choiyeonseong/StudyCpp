#define _CRT_NONSTDC_NO_WARNINGS    // 비표준 함수를 사용했을 때 에러 방지
#include<stdio.h>
#include<conio.h>

class Date
{
protected:
	int year, month, day;

public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutDate() { printf("%d/%d/%d", year, month, day); }
};

class Time
{
protected:
	int hour, min, sec;

public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() { printf("%d:%d:%d", hour, min, sec); }
};

class DateTime :public Date, public Time	// 다중 상속 -> 성능에 무리
{
private:
	bool bEngMessage;
	int milisec;

public:
	DateTime(int y, int m, int d, int h, int min, int s, int ms, bool b = false)
		: Date(y, m, d), Time(h, min, s)	// 다중 상속 받는 모든 멤버를 초기화 해줘야함
	{
		milisec = ms;
		bEngMessage = b;
	}
	void OutNow() {
		printf(bEngMessage ? "Now is " : "지금은 ");
		OutDate();
		putch(' ');
		OutTime();
		printf(".%d", milisec);
		puts(bEngMessage ? "." : "입니다.");
	}
};

int main()
{
	DateTime jiguem(2017, 6, 29, 12, 30, 58, 99);		// 한글로 출력
	DateTime now(2017, 6, 29, 12, 30, 58, 99, true);	// 영어로 출력

	jiguem.OutNow();
	now.OutNow();
}