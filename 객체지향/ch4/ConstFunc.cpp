#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		SetTime(h, m, s);
	}

	void SetTime(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime() const {	// 멤버 함수를 상수화 할때는 맨 뒤에 넣음 
							// 시간을 읽기만 하고 변경하지 않아 상수 함수로 지정했다
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	now.SetTime(11, 22, 33);
	now.OutTime();

	const Time meeting(16, 00, 00);	// meeting이라는 객체를 상수화
	// meeting.SetTime(17,00,00);
	meeting.OutTime();	// 상수 멤버함수라서 상수화된 객체에서 사용 가능
}