#include<stdio.h>

class MathCalc
{
private:
	const double pie;	// ��� ��� : ���� �����Ǹ� �����Ҽ� ���� ���(���Կ����ڸ���������)

public:
	MathCalc(double apie) :pie(apie) {}	// ����� ���� �����ڸ� ���� ���� �������� �ʱ�ȭ ����Ʈ���� �ʱ�ȭ

	void DoCalc(double r) {
		printf("������ %.2f�� ���� �ѷ� = %.2f\n", r, r * 2 * pie);
	}
};

int main()
{
	MathCalc m(3.1416);
	m.DoCalc(5);
}