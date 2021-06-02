#include<stdio.h>

class MathCalc
{
private:
	const double pie;	// 상수 멤버 : 값이 결정되면 변경할수 없는 멤버(대입연산자를쓸수없음)

public:
	MathCalc(double apie) :pie(apie) {}	// 상수는 대입 연산자를 쓸수 없어 생성자의 초기화 리스트에서 초기화

	void DoCalc(double r) {
		printf("반지름 %.2f인 원의 둘레 = %.2f\n", r, r * 2 * pie);
	}
};

int main()
{
	MathCalc m(3.1416);
	m.DoCalc(5);
}