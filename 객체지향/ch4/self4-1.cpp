/*
	Human Ŭ������ ��� ������ ����� �׼��� �Լ��� �ۼ��϶�.
	�̸��� 12 �̸��� ��츸 �޾Ƶ��̰� �� �̻��� �� ���ڿ��� �����Ѵ�.
	���̴� 0~120 ������ �����ϸ� ���� ���� ���̴� 0�� �����Ѵ�.
*/

#include <iostream>
#include <string.h>

using namespace std;

class Human
{
private:
	char name[12];
	int age;

public:
	void GetName() { 
		cout << "�̸��� " << name << " �̴�." << endl;
	}

	void SetName(char* aname) {
		if (strlen(aname) < 12)
		{
			strcpy(name, aname);
		}
		else strcpy(name, "");
	}

	void GetAge() { 
		cout << "���̴� " << age << "�� �̴�." << endl;
	}

	void SetAge(int aage) {
		if (aage >= 0 && aage <= 120)
		{
			age = aage;
		}
		else age = 0;
	}
};

int main()
{
	Human me;
	
	char myname[100];
	int myage;
	
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> myname;
	cout << "���̸� �Է��ϼ��� : ";
	cin >> myage;
	
	me.SetName(myname);
	me.SetAge(myage);

	me.GetName();
	me.GetAge();
}