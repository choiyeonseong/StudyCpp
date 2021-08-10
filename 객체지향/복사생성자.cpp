#include<iostream>
using namespace std;

class A {
public:
	
	A() {
		cout << "������" << endl;
	}
	
	A(const A& rhs) {
		cout << "���� ������" << endl;
	}

	A& operator=(const A& rhs) {
		if (this != &rhs) {	// �ٸ� ���� ���� ����
			cout << "���� ���� ������" << endl;
		}
		return *this;
	}
};


void func_Value(A a) {};		// ���� ������ ȣ��
void func_Reference(A& a) {};	// ���� ������ ȣ�� �ȵ�
void func_Pointer(A* a) {};		// ���� ������ ȣ�� �ȵ�


int main()
{
	// ��ü
	cout << "��ü" << endl;
	A a1;	// �����ڸ� ȣ��
	A a2;	// �����ڸ� ȣ��
	A a3 = a1;	// ��������� ȣ���(�ʱ�ȭ�Ǵ� ����)
	a1 = a2;	// ���� ���� ������ ȣ��

	// �Լ�
	cout << endl << "�Լ�" << endl;
	func_Value(a1);	// ���� ������ ȣ���
	func_Reference(a1);	// ���� ������ ȣ�� �ȵ�
	func_Pointer(&a1);	// ���� ������ ȣ�� �ȵ�

	return 0;
}//��ü�� �����Ǵ� ����� ������ ������ �Ҹ��� ȣ��