/*
	��� ������ ����
	: Ư�� Ŭ������ ���� Ư�� Ÿ���� ����� ����Ű�� ������
	Ŭ���� ���� �� ������ ����Ų��
*/
#include<stdio.h>

class MyClass
{
public:
	int i, j;
	double d;
};

int main() 
{
	MyClass C;
	int MyClass::* pi;	// ��� ������ ����
	double MyClass::* pd;
	int num;

	pi = &MyClass::i;	// �������� ������ ��� ������ ������ �����ϴ°��� ����ų ����� �˷��ٻ� ��ü�� ����� ���� ����Ű�°��� �ƴϴ�
	pi = &MyClass::j;	
	pd = &MyClass::d;
	//pd = &MyClass::i;	// �Ҽ��� ������ Ÿ���� �ٸ�
	//pi = &MyClass::d;
	//pi = &num;		// Ÿ���� ������ Ŭ���� �Ҽ��� �ƴ� ����������
}