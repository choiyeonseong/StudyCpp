#include<stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	// 변환 생성자 오버로딩
	Time(int abssec) {
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	// 변환 함수 : 특정 타입으로 변환하는 캐스트 연산자
	// 너무나도 당연하기 때문에 인수와 리턴값 생략
	// 객체를 정수형으로 변환할때 사용
	operator int() {
		return hour * 3600 + min * 60 + sec;
	}

	void OutTime() {
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	int i = now;	// 모든 수치형과 호환 가능
	printf("i = %d\n", i);
}