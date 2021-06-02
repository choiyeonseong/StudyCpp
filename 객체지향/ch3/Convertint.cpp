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

	// ��ȯ ������ �����ε�
	Time(int abssec) {
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	// ��ȯ �Լ� : Ư�� Ÿ������ ��ȯ�ϴ� ĳ��Ʈ ������
	// �ʹ����� �翬�ϱ� ������ �μ��� ���ϰ� ����
	// ��ü�� ���������� ��ȯ�Ҷ� ���
	operator int() {
		return hour * 3600 + min * 60 + sec;
	}

	void OutTime() {
		printf("���� �ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	int i = now;	// ��� ��ġ���� ȣȯ ����
	printf("i = %d\n", i);
}