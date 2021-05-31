#include<stdio.h>
class Date
{
private:
	int year, month, day;
public:
	void SetDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	void OutDate()
	{
		printf("오늘은 %d년 %d월 %d일입니다.\n", year, month, day);
	}
};

int main()
{
	Date today;

	today.SetDate(2018, 6, 29);
	today.OutDate();
}
