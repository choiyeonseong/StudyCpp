#include<stdio.h>

class Time
{
	//friend class Date;	// Ŭ���� ���� friend�� ��

private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutToday(Date& d) {	// friend�� Time�� ��������� ���� ����
		printf("������ %d�� %d�� %d���̸� ���� �ð��� %d:%d:%d�Դϴ�.\n",
			d.year, d.month, d.day, hour, min, sec);
	}
};

class Date
{
	friend class Time;	// Ŭ���� ���� friend�� ��
	
private:
	int year, month, day;
public:

	Date(int y, int m, int d) { year = y; month = m; day = d; }
	//void OutToday(Time& t) {	// friend�� Time�� ��������� ���� ����
	//	printf("������ %d�� %d�� %d���̸� ���� �ð��� %d:%d:%d�Դϴ�.\n",
	//		year, month, day, t.hour, t.min, t.sec);
	//}
};

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	//d.OutToday(t);
}