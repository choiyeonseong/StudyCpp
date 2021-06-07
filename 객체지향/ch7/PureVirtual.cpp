#include<stdio.h>

// 추상 클래스 : 클래스 전체를 미래에 위임
class Shape	
{
	// 추상클래스가 정의하는 기능 목록 : 인터페이스
public:
	virtual void draw() = 0;
};

// 구체 클래스
class Line :public Shape
{
public:
	virtual void draw() { puts("선을 긋습니다."); }
};

class Circle :public Shape
{
public:
	virtual void draw() { puts("동그라미 그렸다 치고."); }
};

class Rect :public Shape
{
public:
	virtual void draw() { puts("요건 사각형입니다."); }
};

int main()
{
	Shape* pS[3];	// 공동의 집합이 있기때문에 한번에 정의 가능

	//Shape s;
	pS[0] = new Line;
	pS[1] = new Circle;
	pS[2] = new Rect;

	for (int i = 0; i < 3; i++)
	{
		pS[i]->draw();
	}

	for (int i = 0; i < 3; i++)
	{
		delete pS[i];
	}
}