#include<stdio.h>

class Parent {};
class Child:public Parent{};

int main()
{
	Parent P, * pP;
	Child C, * pC;
	int i = 1234;

	pP = static_cast<Parent*>(&C);	// ���� - ��ĳ����(��� ������ �������� ��ȯ)
	pC = static_cast<Child*>(&P);	// ���������� ���� - �ٿ�ĳ����(�θ� ��ü�� ������ �ڽ� Ÿ���� �����ͷ� �ٲ�)
	//pP = static_cast<Parent*>(&i);	// ���� - ������ �����͸� �ƹ��� ���þ��� Ŭ������ �����ͷ� ��ȯ�ϹǷ� ����
	//pC = static_cast<Child*>(&i);	// ���� - ������ ������ class�� ����� ������ ���� �ʾ� ��ȯ�� �ʿ����� ����
}