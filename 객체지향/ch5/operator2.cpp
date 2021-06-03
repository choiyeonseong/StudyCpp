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
	const MyTest operator+ (const MyTest& other) const {
		MyTest r;	// ������ ȣ��
		r.x = this->x + other.x;
		r.y = this->y + other.y;
		return r;	// �ӽ� ��ü�� ����� ���� ���� ������ ȣ�� (��ȿ����)
					// -> ��� ���¸� ������&�� ���� ȣ�� ����(ȿ����)
	}

	// ��ü ���� ����
	//const MyTest operator- (const MyTest& other) const {
	//	MyTest r;	// ������ ȣ��
	//	r.x = this->x - other.x;
	//	r.y = this->y - other.y;
	//	return r;	// �ӽ� ��ü�� ����� ���� ���� ������ ȣ�� (��ȿ����)
	//				// -> ��� ���¸� ������&�� ���� ȣ�� ����(ȿ����)
	//}

	// ���� ������ �Լ��� Ŭ������ ����� �����ϱ� ���ؼ�
	friend const MyTest operator-(const MyTest& rhs1, const MyTest& rhs2);

	// ��ü ���� ����
	const MyTest operator= (const MyTest& other) {	// ���Կ����ڸ� ����� ��쿡�� ������ �ƴ� ��ü�� �����ؾ��Ѵ�
		x = other.x;
		y = other.y;
		return *this;
	}

	void OutData() {
		printf("x : %d\ny : %d\n", x, y);
	}
};

// ���� ������ �Լ� - ����
const MyTest operator-(const MyTest& rhs1, const MyTest& rhs2) {
	MyTest res;
	res.x = rhs1.x - rhs2.x;
	res.y = rhs1.y - rhs2.y;

	return res;
}

int main()
{
	MyTest obj1(20, 40);
	MyTest obj2(10, 20);
	MyTest obj;

	obj = obj1 + obj2;
	obj.OutData();

	//obj = obj1 - obj2;	// ������ �Լ�
	obj = operator-(obj1, obj2);	// ���� ������ �Լ�
	obj.OutData();

	obj.operator=(obj1);
	obj.OutData();
	
	return 0;
}