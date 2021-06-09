/*
	아무도 처리하지 않는 예외는 terminate 함수가 처리하며 
	내부적으로 abort함수를 호출하여 프로그램을 강제 종료
	미처리 예외 핸들러
	: 아무도 처리하지 않는 예외를 받아 극단적인 예외 처리를 수행한다.
*/
#include<stdio.h>
#include<exception>
using namespace std;

void myterm()
{
	puts("처리되지 않은 예외 발생");
	exit(-1);
}

int main()
{
	set_terminate(myterm);	// 이후부터 미처리 예외가 발생할때 이 함수가 호출된다.
	try {
		throw 1;	// catch에서 받지 않아서 미리 지정해놓은 myterm함수가 호출됨
	}
	catch (char* m) {	// 모든 예외를 다 받으려면 catch(...)
	}
}