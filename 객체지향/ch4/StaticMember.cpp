#include<iostream>

class StaticTest {
	static int a;	// static 멤버변수
	int b;
public:
	StaticTest();
	static void setData(int);	// static 멤버함수는 static 멤버변수에 사용한다.
	void getData();
};

int StaticTest::a = 10;	// static 멤버변수 초기화

StaticTest::StaticTest()
{
	b = 20;
}

void StaticTest::getData()
{
	printf("a : %d, b : %d\n",a, b);
}

void StaticTest::setData(int aa)
{
	a = aa;	
	//this->a = aa;	// a는 객체의 것이 아니라서 this라는 포인터를 사용할 수 없음 -> a는 클래스거
}

int main()
{
	StaticTest s1;
	s1.getData();
	StaticTest s2;
	s2.getData();

	s1.setData(30);
	s1.getData();
	s2.getData();

	StaticTest::setData(40);	// 클래스 소속으로 클래스 호출이 가능하다
	s1.getData();
	s2.getData();

	return 0;
}