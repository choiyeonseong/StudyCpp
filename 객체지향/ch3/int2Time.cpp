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

	// ��ȯ ������ - �ӽ� ��ü�� �����Ͽ� ��ȯ�ϰ� ����� ������ �Ѵ�.
	explicit Time(int abssec) {	// explicit - ����� ��ȯ�� ���
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime() {
		printf("���� �ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};
void printTime(Time when) {
	when.OutTime();
}

int main()
{
	Time noon(40000);	// ������� ��ȯ�� ����
	noon.OutTime();
	//noon = 70000;		// ����������� �ʴ�

	//Time now = 60000;	// �������� �ʱ�Ŀ� ��
	//now.OutTime();
	//now = 70000;		
	//now.OutTime();

	//printTime(80000);	// �����߿� ������ �ٷ� ����
}