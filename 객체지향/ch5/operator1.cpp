#include<stdio.h>

class MyTest
{
private:
	int x;
	int y;

public:
	// 생성자
	MyTest(int ax = 0, int ay = 0) { x = ax; y = ay; }	// 디폴트 매개변수로 초기화

	// 연산 함수의 const 위치
	// 1. 반환 자료형을 상수화
	// 2. 연산자 함수로 전달되는 객체를 상수화
	// 3. 연산자 함수를 호출하는 객체를 상수화
	// => 기본형 덧셈과 같은 방식으로 동작하기 위해 상수화 이용
	const MyTest sum(const MyTest& other) const
	{
		MyTest r;
		r.x = x + other.x;
		r.y = y + other.y;
		return r;
	}

	void printData() {
		printf("x : %d\ny : %d\n", x, y);
	}
};

int main()
{
	MyTest obj1(10, 20);
	MyTest obj2(20, 10);
	MyTest obj;

	obj = obj1.sum(obj2);
	
	obj.printData();

	return 0;
}