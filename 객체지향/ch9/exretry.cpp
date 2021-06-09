#include<stdio.h>

int main()
{
	int num;

	try {
		printf("1에서 100사이의 정수를 입력하시오 : ");
		scanf("%d", &num);
		if (num < 1 || num>100) throw num;	// 틀린 입력은 정확하게 적발하지만 다시 입력하도록 돌아가지는 못한다.
		printf("입력한 수 = %d\n", num);
	}
	catch (int num) {
		printf("%d는 1에서 100사이의 정수가 아닙니다.\n", num);
	}
}