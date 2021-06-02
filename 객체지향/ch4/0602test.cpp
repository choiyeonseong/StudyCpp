/*
	ȸ���̸�, ��ȭ��ȣ, �ּ�, cnt��
	��������� ���� class�� �����Ͻÿ�.
*/

#include<iostream>
#include<string.h>

class CMember
{
	char name[20];
	char phone[20];
	char addr[40];
	static int cnt;
public:
	// ������
	// �Ű������� ����("")���� �޾ƿ� ���� �ڷ����� const�� �������ش�
	CMember(const char* aname,const char* aphone,const char* aaddr)	
	{
		strcpy(name, aname);
		strcpy(phone, aphone);
		strcpy(addr, aaddr);
		cnt++;
	}
	~CMember() { printf("�Ҹ�~~\n"); cnt--; }
	void getData()
	{
		printf("�̸� : %s\n", name);
		printf("��ȭ��ȣ : %s\n", phone);
		printf("�ּ� : %s\n", addr);
	}
	// static ������ cnt�� �����ϱ� ����, static �Լ��� ���
	static void OutCount() {
		printf("count = %d\n", cnt);
	}
};

int CMember::cnt = 0;	// ���� ��� ������ Ŭ���� �ܺο� ::�����ڿ� �Բ� �Ҽ��� ���� ������ �����ϰ� �ʱ�ȭ

int main()
{
	CMember* mem = new CMember("�谳��", "010-2325-3464", "�λ�� ���屺");

	mem->getData();
	
	CMember::OutCount();	// ���� ��� �Լ��� ���� ��� ������ ����

	delete mem;
	
	CMember newMem1("�ֿ���", "010-2325-3464", "�λ�� ���屺");	// �����ڷ� ��ü �ʱ�ȭ
	CMember newMem2("ȫ�浿", "010-1411-3464", "�λ�� ���屺");	// �����ڷ� ��ü �ʱ�ȭ
	
	newMem1.getData();
	newMem2.getData();

	CMember::OutCount();	// ���� ��� �Լ��� ���� ��� ������ ����

	return 0;
}