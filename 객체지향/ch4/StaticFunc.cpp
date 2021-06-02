#include<stdio.h>
class Simple
{
private:
	int value;
	static int count;
public:
	Simple() { count++; }
	~Simple() { count--; }
	static void InitCount() {
		count = 0;
	}
	static void OutCount()
	{
		printf("���� ��ü ���� = %d\n", count);
	}
};

int Simple::count;

int main()
{
	Simple::InitCount();				// ī��Ʈ 0
	Simple::OutCount();

	Simple s, * ps;						// ī��Ʈ 1
	Simple::OutCount();

	ps = new Simple;					// ī��Ʈ 2
	Simple::OutCount();

	delete ps;							// ī��Ʈ 1
	Simple::OutCount();
	
	printf("ũ�� = %d\n", sizeof(s));
}										// ī��Ʈ 0