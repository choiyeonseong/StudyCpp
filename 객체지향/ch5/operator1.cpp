#include<stdio.h>

class MyTest
{
private:
	int x;
	int y;

public:
	// ������
	MyTest(int ax = 0, int ay = 0) { x = ax; y = ay; }	// ����Ʈ �Ű������� �ʱ�ȭ

	// ���� �Լ��� const ��ġ
	// 1. ��ȯ �ڷ����� ���ȭ
	// 2. ������ �Լ��� ���޵Ǵ� ��ü�� ���ȭ
	// 3. ������ �Լ��� ȣ���ϴ� ��ü�� ���ȭ
	// => �⺻�� ������ ���� ������� �����ϱ� ���� ���ȭ �̿�
	const MyTest sum(const MyTest& other) const
	{
		MyTest r;
		r.x = x + other.x;
		r.y = y + other.y;
		return r;
	}

	void printData() {
		printf("x : %d\ny : %d\n", x, y);
	}
};

int main()
{
	MyTest obj1(10, 20);
	MyTest obj2(20, 10);
	MyTest obj;

	obj = obj1.sum(obj2);
	
	obj.printData();

	return 0;
}