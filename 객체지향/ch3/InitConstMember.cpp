/* 
	��� �ʱ�ȭ ����Ʈ
	: Ư���� ó�� ���� �ܼ� ���Ը� �Ҷ�
*/
#include<stdio.h>
class Some
{
public:
	const int total;	// const�� ���� ������ ������ ����
	
	// �ʱ�ȭ ����Ʈ ���
	Some(int atotal) :total(atotal) {}	
	
	//Some(int atotal) {	// �Ϲ����� ���Կ����� ���� �ʱ�ȭ ����� �ȵȴ�.
	//	total = atotal;		// ���const�� ���� �������� �ʱ�ȭ �Ұ�
	//}
	
	void OutTotal() { printf("%d\n", total); }
};

int main()
{
	Some S(5);
	S.OutTotal();
}