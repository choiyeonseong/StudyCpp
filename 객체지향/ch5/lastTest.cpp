/*
	step 1 : ������, �����Ҵ�, �Ҵ� ����, print�Լ�
	step 2 : ���� ������
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
	// ������
	Human(const char* aname = "", int aage = 0) {	// ����Ʈ �Ű������� ����ؼ� �μ��� ���� �����ڸ� ���
		// name ���� �Ҵ�
		name = new char[strlen(aname) + 1];

		strcpy(name, aname);
		age = aage;
	}
	// �Ҹ���
	~Human() {
		printf("�Ҹ���\n");
		delete[] name;
	}
	// ���� �����ڤ�
	Human(Human& other) {
		name = new char[strlen(other.name) + 1];

		strcpy(name, other.name);
		age = other.age;
	}
	// ��� �Լ�
	void printHuman() {
		printf("%d�� %s�Դϴ�.\n", age, name);
	}
	// ���� ������ �Լ�
	Human& operator=(Human &other) {	// ������ ��ȯ ���ָ� �ӽð�ü�� ������ ����
		name = new char[strlen(other.name) + 1];

		strcpy(name, other.name);
		age = other.age;

		return *this;
	}
};

int main()
{
	Human myH("����", 25);	// ������ ȣ��
	myH.printHuman();

	Human youH(myH);		// ���� ������ ȣ��
	youH.printHuman();

	Human Xman;
	Xman = myH;				// ���� ������ �Լ� ȣ��
	Xman.printHuman();

	return 0;
}