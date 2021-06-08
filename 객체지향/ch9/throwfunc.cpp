#include<stdio.h>
void divide(int a, int d)
{
	if (d == 0) throw"0으로는 나눌수 없습니다.";
	printf("나누기 결과 = %d입니다.\n",a/d);
}

int main()
{
	try {
		divide(10, 0);
	}
	catch (const char* message) {	// throw를 받아줄 catch문이 없으면 프로그램 강제종료
		puts(message);
	}

	// 스택프레임을 호출전의 상태로 복구하기 때문에 
	// 예외에 의해 강제 리턴했음에도 잘 실행됨
	divide(10, 5);
}