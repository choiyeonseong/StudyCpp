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
		printf("����ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}

	// ���� ������
	Time(const Time& other) {
		hour = other.hour;
		min = other.min;
		sec = other.sec;
	}
};

int main()
{
	Time now(12, 34, 56);
	Time then = now;	// ���� ������ ȣ��

	then.OutTime();
}