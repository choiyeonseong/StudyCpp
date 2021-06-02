#include<stdio.h>

class Enemy
{
private:
	const int Speed;
public:
	Enemy(int aSpeed) :Speed(aSpeed) {}		// 상수 멤버를 생성자의 초기화 리스트에서 객체별로 초기화한다.
	void Move() {
		printf("%d의 속도로 움직인다.\n", Speed);
	}
};

int main()
{
	Enemy e1(10), e2(20);
	e1.Move();
	e2.Move();
}