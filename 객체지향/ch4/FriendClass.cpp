#include<stdio.h>

class Time
{
	//friend class Date;	// 클래스 끼리 friend가 됨

private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutToday(Date& d) {	// friend라서 Time의 멤버변수에 접근 가능
		printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
			d.year, d.month, d.day, hour, min, sec);
	}
};

class Date
{
	friend class Time;	// 클래스 끼리 friend가 됨
	
private:
	int year, month, day;
public:

	Date(int y, int m, int d) { year = y; month = m; day = d; }
	//void OutToday(Time& t) {	// friend라서 Time의 멤버변수에 접근 가능
	//	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
	//		year, month, day, t.hour, t.min, t.sec);
	//}
};

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	//d.OutToday(t);
}