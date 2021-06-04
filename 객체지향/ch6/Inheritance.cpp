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

class Student :public Human	// public���� ��ӹ����� �θ�Ŭ������ �ν��Ͻ��� ���� ����
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
		printname();	// public���� ��ӹ����� �θ�Ŭ������ �ν��Ͻ��� ���� ����
		cout << "My Major is " << major << endl;
	}
};

int main()
{
	Human my("����");
	//my.printname();

	Student s("����", "Iot");
	//s.printname();	// public���� ��ӹ����� �θ�Ŭ������ �ν��Ͻ��� ���� ����
	s.printMajor();

	return 0;
}