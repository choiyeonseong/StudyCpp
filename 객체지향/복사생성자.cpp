#include<iostream>
using namespace std;

class A {
public:
	
	A() {
		cout << "생성자" << endl;
	}
	
	A(const A& rhs) {
		cout << "복사 생성자" << endl;
	}

	A& operator=(const A& rhs) {
		if (this != &rhs) {	// 다를 때만 복사 수행
			cout << "복사 대입 연산자" << endl;
		}
		return *this;
	}
};


void func_Value(A a) {};		// 복사 생성자 호출
void func_Reference(A& a) {};	// 복사 생성자 호출 안됨
void func_Pointer(A* a) {};		// 복사 생성자 호출 안됨


int main()
{
	// 객체
	cout << "객체" << endl;
	A a1;	// 생성자만 호출
	A a2;	// 생성자만 호출
	A a3 = a1;	// 복사생성자 호출됨(초기화되는 시점)
	a1 = a2;	// 복사 대입 연산자 호출

	// 함수
	cout << endl << "함수" << endl;
	func_Value(a1);	// 복사 생성자 호출됨
	func_Reference(a1);	// 복사 생성자 호출 안됨
	func_Pointer(&a1);	// 복사 생성자 호출 안됨

	return 0;
}//객체가 생성되는 블록이 끝나는 시점에 소멸자 호출