#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

class CTest {
private:
	int m_num;
	int* ptr;

public:
	// Default 생성자
	CTest() {
		printf("디폴트 생성자 호출\n");
	}

	// 인수 하나를 가지는 변환 생성자
	CTest(int num) {
		m_num = num;
		printf("생성자 호출 : %d\n", m_num);
	}

	// 인수 두개를 가지는 생성자
	CTest(int num, int* ptr) {
		this->m_num = num;
		this->ptr = new int;	// 동적 할당
		this->ptr = ptr;
		printf("인자 두개 생성자 호출 : %d, %p", m_num, ptr);
	}

	// 복사 생성자
	CTest(CTest &other) {
		this->m_num = other.m_num;
		this->ptr = new int;	// 동적 할당(깊은 복사)
		this->ptr = other.ptr;
		printf("복사 생성자 호출 : %d, %p", m_num, ptr);
	}

	// 파괴자
	~CTest(){
		delete ptr;		// 동적 할당한 경우 소멸자에서 해제시키다
	}

	void getData() {
		printf("%d\n", m_num);
	}
};

int main()
{
	/* 기본 자료형 */
	int a = 10;
	int b(20);	// cpp에서 제공하는 초기화 타입
	//int c = a;
	int c(a);	// 복사 생성자
	
	printf("%d, %d, %d\n", a, b, c);

	/* 사용자 자료형 */
	// 인수 1개의 생성자 호출
	CTest c1(100);	// 에러 : 디폴트 생성자는 인수가 없기 때문에
					// => 사용자 생성자 만들어주면 가능

	// 디폴트 생성자 호출
	CTest c2;		// 에러 : 디폴트가 아닌 새로운 생성자를 만들어서
					// => 디폴트 생성자를 만들어주면 가능
	
	// 복사 생성자 호출
	CTest c3(c1);	// 얕은 복사 : 주소를 복사한다.(참조를 전달받기 때문에)
	
	// 인수 2개 생성자 호출
	CTest c4(50, nullptr);	
	// 복사 생성자 호출
	CTest c5(c4);	// 깊은 복사 : 새로 메모리를 할당해서 주소를 복사한다.

	c3.getData();
	c5.getData();

	return 0;
}