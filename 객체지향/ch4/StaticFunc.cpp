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
		printf("현재 객체 개수 = %d\n", count);
	}
};

int Simple::count;

int main()
{
	Simple::InitCount();				// 카운트 0
	Simple::OutCount();

	Simple s, * ps;						// 카운트 1
	Simple::OutCount();

	ps = new Simple;					// 카운트 2
	Simple::OutCount();

	delete ps;							// 카운트 1
	Simple::OutCount();
	
	printf("크기 = %d\n", sizeof(s));
}										// 카운트 0