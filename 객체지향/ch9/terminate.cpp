/*
	�ƹ��� ó������ �ʴ� ���ܴ� terminate �Լ��� ó���ϸ� 
	���������� abort�Լ��� ȣ���Ͽ� ���α׷��� ���� ����
	��ó�� ���� �ڵ鷯
	: �ƹ��� ó������ �ʴ� ���ܸ� �޾� �ش����� ���� ó���� �����Ѵ�.
*/
#include<stdio.h>
#include<exception>
using namespace std;

void myterm()
{
	puts("ó������ ���� ���� �߻�");
	exit(-1);
}

int main()
{
	set_terminate(myterm);	// ���ĺ��� ��ó�� ���ܰ� �߻��Ҷ� �� �Լ��� ȣ��ȴ�.
	try {
		throw 1;	// catch���� ���� �ʾƼ� �̸� �����س��� myterm�Լ��� ȣ���
	}
	catch (char* m) {	// ��� ���ܸ� �� �������� catch(...)
	}
}