#include<iostream>

using namespace std;

class A
{
public:
	void AFunc()
	{
		cout << "A::AFunc()" << endl;
	}
};

class B:public A
{
public:
	void BFunc()
	{
		cout << "B::BFunc()" << endl;
	}
};

class C :public B
{
public:
	void CFunc()
	{
		cout << "C::CFunc()" << endl;
	}
};

int main()
{
	// ������ Ÿ�Կ� ���� ���������� ����� �� �ִ� ������ ������
	// �θ� Ŭ������ �ڽ� Ŭ������ ����ų �� ����
	// �ڽ��� �θ� ����ų �� ����
	// C* pcc = new A;	// �Ұ���

	A* pa = new C;	// ���� Ŭ���� Ÿ���� �����Ͱ� �Ļ���ü�� ����Ű�� �ִ�.
	pa->AFunc();

	B* pb = new C;
	pb->AFunc();
	pb->BFunc();

	C* pc = new C;
	pc->AFunc();
	pc->BFunc();
	pc->CFunc();

	return 0;
}