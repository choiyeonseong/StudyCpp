/*
	����Լ� �����߿� �ٸ� ��� �Լ��� ���������� ȣ���ؾ��Ѵٸ� ��� ��� �Լ��� �μ��� �޾ƾ� �ϴµ�
	�̶� �ʿ��� ���� ��� ������ �μ��̴�.
*/
#include<stdio.h>

class Calc
{
public:
	void Op1(int a, int b) { printf("%d\n", a + b); }
	void Op2(int a, int b) { printf("%d\n", a - b); }
	void Op3(int a, int b) { printf("%d\n", a * b); }

	void DoCalc(void (Calc::* fp)(int, int), int a, int b)
	{
		puts("���ݺ��� ���� ����� ��ǥ�ϰڽ��ϴ�.");
		printf("%d�� %d�� ���� ��� : ", a, b);
		(this->*fp)(a, b);	// ��� ������ �μ�
		puts("�̻��Դϴ�.");
	}
};

int main()
{
	int ch;
	Calc c;
	int a = 3, b = 4;
	void (Calc:: * arop[3])(int, int) = { &Calc::Op1,&Calc::Op2 ,&Calc::Op3 };	// �Լ� ������

	printf("���� ����� �����Ͻÿ�. 0=���ϱ�, 1=����, 2=���ϱ� : ");
	scanf("%d", &ch);

	if (ch >= 0 && ch <= 2) {
		c.DoCalc(arop[ch], a, b);	// �Լ� �����ʹ� �������� �ٸ� �Լ��� �μ��� �����Ҽ��ִ�.
									// ��� ������ ������ ����Լ����� �ٸ� ��� �Լ��� �����Ѵ�.
	}

}