#include<stdio.h>

class Enemy
{
private:
	const int Speed;
public:
	Enemy(int aSpeed) :Speed(aSpeed) {}		// ��� ����� �������� �ʱ�ȭ ����Ʈ���� ��ü���� �ʱ�ȭ�Ѵ�.
	void Move() {
		printf("%d�� �ӵ��� �����δ�.\n", Speed);
	}
};

int main()
{
	Enemy e1(10), e2(20);
	e1.Move();
	e2.Move();
}