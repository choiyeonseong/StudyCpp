#include<stdio.h>

class MathCalc
{
private:
	static const double pie;	// ���� ���
public:
	MathCalc() {}
	void DoCalc(double r) {
		printf("������ %.2f�� ���� �ѷ� = %.2f\n", r, r * 2 * pie);
	}
};

const double MathCalc::pie = 3.1416;	// ��������� �����ڿ��� �ʱ�ȭ�� �� ���� Ŭ���� �ܺο� �����ϸ鼭 �ʱ�ȭ �ϴ°��� ��Ģ

int main()
{
	MathCalc m;
	m.DoCalc(5);
}