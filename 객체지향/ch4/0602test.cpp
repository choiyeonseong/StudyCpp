/*
	회원이름, 전화번호, 주소, cnt를
	멤버변수로 갖는 class를 설계하시오.
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
	// 생성자
	// 매개변수를 원본("")으로 받아올 때는 자료형을 const로 지정해준다
	CMember(const char* aname,const char* aphone,const char* aaddr)	
	{
		strcpy(name, aname);
		strcpy(phone, aphone);
		strcpy(addr, aaddr);
		cnt++;
	}
	~CMember() { printf("소멸~~\n"); cnt--; }
	void getData()
	{
		printf("이름 : %s\n", name);
		printf("전화번호 : %s\n", phone);
		printf("주소 : %s\n", addr);
	}
	// static 변수인 cnt에 접근하기 위해, static 함수를 사용
	static void OutCount() {
		printf("count = %d\n", cnt);
	}
};

int CMember::cnt = 0;	// 정적 멤버 변수는 클래스 외부에 ::연산자와 함께 소속을 밝혀 별도로 정의하고 초기화

int main()
{
	CMember* mem = new CMember("김개똥", "010-2325-3464", "부산시 기장군");

	mem->getData();
	
	CMember::OutCount();	// 정적 멤버 함수로 정적 멤버 변수에 접근

	delete mem;
	
	CMember newMem1("최연성", "010-2325-3464", "부산시 기장군");	// 생성자로 객체 초기화
	CMember newMem2("홍길동", "010-1411-3464", "부산시 기장군");	// 생성자로 객체 초기화
	
	newMem1.getData();
	newMem2.getData();

	CMember::OutCount();	// 정적 멤버 함수로 정적 멤버 변수에 접근

	return 0;
}