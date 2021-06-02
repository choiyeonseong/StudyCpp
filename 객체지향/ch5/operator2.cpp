#include<stdio.h>

class MyTest
{
private:
	int x;
	int y;

public:
	// 인수2개 생성자
	MyTest(int a = 0, int b = 0) {
		x = a; 
		y = b;
		printf("인수 2개 생성자 호출 %d / %d\n", a, b);
	}

	// 복사 생성자
	MyTest(MyTest& rhs) :x(rhs.x), y(rhs.y) {
		printf("복사 생성자 호출 %d / %d\n", x, y);
	}

	// 객체 덧셈 연산
	const MyTest& operator+ (const MyTest& other) const {
		MyTest r;	// 생성자 호출
		r.x = this->x + other.x;
		r.y = this->y + other.y;
		return r;	// 임시 객체가 만들어 져서 복사 생성자 호출 (비효율적)
					//-> 출력 형태를 참조자&로 쓰면 호출 안함(효율적)
	}

	// 객체 뺄셈 연산
	const MyTest& operator- (const MyTest& other) const {
		MyTest r;	// 생성자 호출
		r.x = this->x - other.x;
		r.y = this->y - other.y;
		return r;	// 임시 객체가 만들어 져서 복사 생성자 호출 (비효율적)
					//-> 출력 형태를 참조자&로 쓰면 호출 안함(효율적)
	}

	void OutData() {
		printf("x : %d\ny : %d\n", x, y);
	}
};

int main()
{
	MyTest obj1(20, 40);
	MyTest obj2(10, 20);
	MyTest obj;

	obj = obj1 + obj2;
	obj.OutData();

	obj = obj1 - obj2;
	obj.OutData();

	return 0;
}