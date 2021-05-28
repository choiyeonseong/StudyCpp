#include<stdio.h>
#include<malloc.h>
#include<string.h>

/*
	레퍼런스를 매개변수로 받는 함수는
	호출부의 형식이 값호출과 같아 함수 원형을 봐야만 참조호출인지 값호출인지 알수있음
	=>>레퍼런스를 사용하면 편하구나~ 형식매개변수로 사용할때 능력 발휘
*/
void InputNameByRef(char*& Name)	// 포인터의 레퍼런스
{
	Name = (char*)malloc(32);
	strcpy(Name, "kim sang hyung");
}

int main()
{
	/*
	char* Name;

	InputNameByRef(Name);
	printf("이름은 %s입니다.\n", Name);
	free(Name);
	*/

	int a = 10;
	int& ra = a;
	int* pa = &ra;
	printf("%p %p %p", &a, &ra, pa);	// 모두 동일하게 변수 a를 가리키고 있음
}

/*
// 레퍼런스를 사용하지 않는 경우
void InputName(char* *Name)	// 이중포인터 사용해야 함
{
	*Name = (char*)malloc(32);
	strcpy(*Name, "kim sang hyung");
}

int main()
{
	char* Name = NULL;

	InputName(&Name);
	printf("이름은 %s입니다.\n", Name);
	free(Name);
}
*/
