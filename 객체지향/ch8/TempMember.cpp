/*
	템플릿 멤버 함수
	: 함수 템플릿과 같되 클래스에 소속되어 있다는 것만 다름
*/
#include<stdio.h>

class Util
{
public:
	template <typename T>
	void swap(T& a, T& b)
	{
		T t;
		t = a; a = b; b = t;
	}
};

int main()
{
	Util u;
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	char e = 'e', f = 'f';

	u.swap<int>(a, b);	// 명시적 인수
	u.swap(c, d);
	u.swap(e, f);

	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
	printf("e = %c, f = %c\n", e, f);
}


/* 
	템플릿 클래스 
*/
//template <typename T>
//class Util
//{
//public:
//
//	void swap(T& a, T& b)
//	{
//		T t;
//		t = a; a = b; b = t;
//	}
//};
//
//int main()
//{
//	// 템플릿 클래스 일때
//	Util<int> u;	// 명시적 인수
//	Util<double> u1;
//	Util<char> u2;
//
//	int a = 3, b = 4;
//	double c = 1.2, d = 3.4;
//	char e = 'e', f = 'f';
//
//	u.swap(a, b);	
//	u1.swap(c, d);
//	u2.swap(e, f);
//
//	printf("a = %d, b = %d\n", a, b);
//	printf("c = %f, d = %f\n", c, d);
//	printf("e = %c, f = %c\n", e, f);
//}
