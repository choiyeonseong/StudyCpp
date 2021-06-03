/*
	step 1 : 생성자, 동적할당, 할당 해제, print함수
	step 2 : 복사 생성자
	step 3 : operator=
*/
#include<stdio.h>
#include<string.h>

class Human
{
private:
	char* name;
	int age;
public:
	// 생성자
	Human(const char* aname = "", int aage = 0) {	// 디폴트 매개변수를 사용해서 인수가 없는 생성자를 대신
		// name 동적 할당
		name = new char[strlen(aname) + 1];

		strcpy(name, aname);
		age = aage;
	}
	// 소멸자
	~Human() {
		printf("소멸자\n");
		delete[] name;
	}
	// 복사 생성자ㅌ
	Human(Human& other) {
		name = new char[strlen(other.name) + 1];

		strcpy(name, other.name);
		age = other.age;
	}
	// 출력 함수
	void printHuman() {
		printf("%d살 %s입니다.\n", age, name);
	}
	// 대입 연산자 함수
	Human& operator=(Human &other) {	// 참조를 반환 해주면 임시객체를 만들지 않음
		name = new char[strlen(other.name) + 1];

		strcpy(name, other.name);
		age = other.age;

		return *this;
	}
};

int main()
{
	Human myH("연성", 25);	// 생성자 호출
	myH.printHuman();

	Human youH(myH);		// 복사 생성자 호출
	youH.printHuman();

	Human Xman;
	Xman = myH;				// 대입 연산자 함수 호출
	Xman.printHuman();

	return 0;
}