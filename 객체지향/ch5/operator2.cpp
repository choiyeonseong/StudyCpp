#include<stdio.h>

class MyTest
{
private:
	int x;
	int y;

public:
	// �μ�2�� ������
	MyTest(int a = 0, int b = 0) {
		x = a; 
		y = b;
		printf("�μ� 2�� ������ ȣ�� %d / %d\n", a, b);
	}

	// ���� ������
	MyTest(MyTest& rhs) :x(rhs.x), y(rhs.y) {
		printf("���� ������ ȣ�� %d / %d\n", x, y);
	}

	// ��ü ���� ����
	const MyTest& operator+ (const MyTest& other) const {
		MyTest r;	// ������ ȣ��
		r.x = this->x + other.x;
		r.y = this->y + other.y;
		return r;	// �ӽ� ��ü�� ����� ���� ���� ������ ȣ�� (��ȿ����)
					//-> ��� ���¸� ������&�� ���� ȣ�� ����(ȿ����)
	}

	// ��ü ���� ����
	const MyTest& operator- (const MyTest& other) const {
		MyTest r;	// ������ ȣ��
		r.x = this->x - other.x;
		r.y = this->y - other.y;
		return r;	// �ӽ� ��ü�� ����� ���� ���� ������ ȣ�� (��ȿ����)
					//-> ��� ���¸� ������&�� ���� ȣ�� ����(ȿ����)
	}

	void OutData() {
		printf("x : %d\ny : %d\n", x, y);
	}
};

int main()
{
	MyTest obj1(20, 40);
	MyTest obj2(10, 20);
	MyTest obj;

	obj = obj1 + obj2;
	obj.OutData();

	obj = obj1 - obj2;
	obj.OutData();

	return 0;
}