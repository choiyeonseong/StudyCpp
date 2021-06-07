#include<stdio.h>
#include<string.h>

template<typename T>
void swap(T& a, T& b)
{
	T t;
	t = a; a = b; b = t;
}

class Human
{
private:
	char* name;
	int age;
public:
	// 생성자
	Human()
	{
		name = new char[1];
		name[0] = NULL;
		age = 0;
	}
	Human(const char* aname, int aage)
	{
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		age = aage;
	}
	// 변환생성자(인수 1개짜리 생성자), 복사생성자(참조형태의 매개변수를 가진 생성자)
	Human(const Human& other)
	{
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}
	// 대입 연산자
	Human& operator=(const Human& other)	// 교환을 위해 =대입 연산자를 정의해야함
	{
		if (this != &other)
		{
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			age = other.age;
		}
		return *this;
	}
	// 파괴자
	~Human()
	{
		delete[] name;
	}

	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human lee("이수만", 10);
	Human park("박진영", 20);
	lee.intro();
	park.intro();
	swap(lee, park);
	lee.intro();
	park.intro();
}