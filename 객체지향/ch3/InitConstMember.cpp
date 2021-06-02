/* 
	멤버 초기화 리스트
	: 특별한 처리 없이 단순 대입만 할때
*/
#include<stdio.h>
class Some
{
public:
	const int total;	// const는 정적 데이터 영역에 저장
	
	// 초기화 리스트 방식
	Some(int atotal) :total(atotal) {}	
	
	//Some(int atotal) {	// 일반적인 대입연산을 통한 초기화 방식은 안된다.
	//	total = atotal;		// 상수const라서 대입 연산으로 초기화 불가
	//}
	
	void OutTotal() { printf("%d\n", total); }
};

int main()
{
	Some S(5);
	S.OutTotal();
}