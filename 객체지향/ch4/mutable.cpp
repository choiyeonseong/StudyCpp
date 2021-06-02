#include<stdio.h>

class Some
{
private:
	mutable int temp;	// 객체의 상수성과 관계없이 언제나 수정이 가능하다.
public:
	Some() {}
	void method() const { temp = 0; }
};

int main()
{
	Some s;
	s.method();

	const Some t;
	t.method();
}