#include<stdio.h>

class Time
{
public:
	int hour, min, sec;

	void OutTime() {
		printf("����ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};

int main()
{
	Time now;
	int Time::* pi;	// time�� ������ ��� ������ ����Ű�� pi�� ����

	pi = &Time::hour;
	now.*pi = 12;

	pi = &Time::min;	// ��� �����ʹ� �����̹Ƿ� ���� �߿� ����Ű�� ����� �ٲܼ� �ִ�.
	now.*pi = 34;

	pi = &Time::sec;
	now.*pi = 56;

	now.OutTime();

	/*
		Time�� ��ü�� ����Ű�� �����͸� ������ �ִٸ� .*������ ��ſ� ->*�����ڸ� ����Ѵ�.
		���� Ÿ���� ���� ������ ����Ų�ٴ� �鿡�� �Ϲ� �����Ϳ� ����� ����
		������ Ŭ���� ������ ����� ���ѵȴٴ� ���� Ư���ϴ�
	*/
}