#include<stdio.h>

class MathCalc
{
private:
	static const double pie;	// 공유 상수
public:
	MathCalc() {}
	void DoCalc(double r) {
		printf("반지름 %.2f인 원의 둘레 = %.2f\n", r, r * 2 * pie);
	}
};

const double MathCalc::pie = 3.1416;	// 정적멤버는 생성자에서 초기화할 수 없고 클래스 외부에 정의하면서 초기화 하는것이 원칙

int main()
{
	MathCalc m;
	m.DoCalc(5);
}