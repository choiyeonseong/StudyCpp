#include<stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime()
	{
		printf("현재시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}

	// 복사 생성자
	Time(const Time& other) {
		hour = other.hour;
		min = other.min;
		sec = other.sec;
	}
};

int main()
{
	Time now(12, 34, 56);
	Time then = now;	// 복사 생성자 호출

	then.OutTime();
}