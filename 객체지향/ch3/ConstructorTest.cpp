#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

class CTest {
private:
	int m_num;
	int* ptr;

public:
	// Default ������
	CTest() {
		printf("����Ʈ ������ ȣ��\n");
	}

	// �μ� �ϳ��� ������ ��ȯ ������
	CTest(int num) {
		m_num = num;
		printf("������ ȣ�� : %d\n", m_num);
	}

	// �μ� �ΰ��� ������ ������
	CTest(int num, int* ptr) {
		this->m_num = num;
		this->ptr = new int;	// ���� �Ҵ�
		this->ptr = ptr;
		printf("���� �ΰ� ������ ȣ�� : %d, %p", m_num, ptr);
	}

	// ���� ������
	CTest(CTest &other) {
		this->m_num = other.m_num;
		this->ptr = new int;	// ���� �Ҵ�(���� ����)
		this->ptr = other.ptr;
		printf("���� ������ ȣ�� : %d, %p", m_num, ptr);
	}

	// �ı���
	~CTest(){
		delete ptr;		// ���� �Ҵ��� ��� �Ҹ��ڿ��� ������Ű��
	}

	void getData() {
		printf("%d\n", m_num);
	}
};

int main()
{
	/* �⺻ �ڷ��� */
	int a = 10;
	int b(20);	// cpp���� �����ϴ� �ʱ�ȭ Ÿ��
	//int c = a;
	int c(a);	// ���� ������
	
	printf("%d, %d, %d\n", a, b, c);

	/* ����� �ڷ��� */
	// �μ� 1���� ������ ȣ��
	CTest c1(100);	// ���� : ����Ʈ �����ڴ� �μ��� ���� ������
					// => ����� ������ ������ָ� ����

	// ����Ʈ ������ ȣ��
	CTest c2;		// ���� : ����Ʈ�� �ƴ� ���ο� �����ڸ� ����
					// => ����Ʈ �����ڸ� ������ָ� ����
	
	// ���� ������ ȣ��
	CTest c3(c1);	// ���� ���� : �ּҸ� �����Ѵ�.(������ ���޹ޱ� ������)
	
	// �μ� 2�� ������ ȣ��
	CTest c4(50, nullptr);	
	// ���� ������ ȣ��
	CTest c5(c4);	// ���� ���� : ���� �޸𸮸� �Ҵ��ؼ� �ּҸ� �����Ѵ�.

	c3.getData();
	c5.getData();

	return 0;
}