/*
	try 블록 함수
	: 함수의 실질적인 코드가 모두 try블록에 작성되어 있으니 본체를 따로 만들 필요없이 try 블록 자체를 함수의 본체로 만들면 된다.
	함수의 시작과 끝을 표시하는 {}괄호를 없애고 try와 catch 블록을 함수의 본체인 것 처럼 작성하는 것이다.
*/

#include<stdio.h>

void divide(int a, int d)
try {
	if (d == 0) throw "0으로는 나눌수 없습니다.";
	printf("나누기 결과 = %d입니다.\n", a / d);
}
catch (const char* message) {
	puts(message);
}

int main()
{
	divide(10, 0);
}