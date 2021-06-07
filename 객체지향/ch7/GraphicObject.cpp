#include <stdio.h>

class Shape
{
public:
	virtual void draw() { puts("���� ������Ʈ�Դϴ�."); }	// ��Ʈ�� �Լ��� �������� �����ϸ� �Ļ� Ŭ������ �Լ��� �ڵ����� ������ �ȴ�.
};

class Line : public Shape
{
public:
	void draw() { puts("���� �߽��ϴ�."); }
};

class Circle : public Shape
{
public:
	void draw() { puts("���׶�� �׷ȴ� ġ��."); }
};

class Rect : public Shape
{
public:
	void draw() { puts("��� �簢���Դϴ�."); }
};

class Trianle :public Shape
{
public:
	void draw() { puts("���� ���� �߰��� �ﰢ���̴�."); }
};

int main()
{
	Shape* ar[] = { new Shape(), new Rect(), new Circle(), new Rect(), new Line(), new Trianle() };	// ������ �迭

	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) {
		ar[i]->draw();
	}
	
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) {
		delete ar[i];
	}
}
