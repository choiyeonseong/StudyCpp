#include<iostream>
using namespace std;

class Human
{
private:
	char* name;
public:
	Human(const char* aname) {
		int len = strlen(aname) + 1;
		name = new char[len];
		strcpy_s(name, len, aname);
	}
	~Human() {
		delete[] name;
	}
	void printname()
	{
		cout << "My name is " << name << endl;
	}
};

class Student :public Human	// public으로 상속받으면 부모클래스의 인스턴스에 접근 가능
{
private:
	char* major;

public:
	Student(const char* aname, const char* amajor) :Human(aname)
	{
		int len = strlen(amajor) + 1;
		major = new char[len];
		strcpy_s(major, len, amajor);
	}
	~Student()
	{
		delete[] major;
	}
	void printMajor()
	{
		printname();	// public으로 상속받으면 부모클래스의 인스턴스에 접근 가능
		cout << "My Major is " << major << endl;
	}
};

int main()
{
	Human my("연성");
	//my.printname();

	Student s("연성", "Iot");
	//s.printname();	// public으로 상속받으면 부모클래스의 인스턴스에 접근 가능
	s.printMajor();

	return 0;
}