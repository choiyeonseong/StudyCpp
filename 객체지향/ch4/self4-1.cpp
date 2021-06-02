/*
	Human 클래스의 멤버 변수를 숨기고 액세서 함수를 작성하라.
	이름은 12 미만인 경우만 받아들이고 그 이상은 빈 문자열을 대입한다.
	나이는 0~120 범위만 인정하며 범위 밖의 나이는 0을 대입한다.
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
		cout << "이름은 " << name << " 이다." << endl;
	}

	void SetName(char* aname) {
		if (strlen(aname) < 12)
		{
			strcpy(name, aname);
		}
		else strcpy(name, "");
	}

	void GetAge() { 
		cout << "나이는 " << age << "살 이다." << endl;
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
	
	cout << "이름을 입력하세요 : ";
	cin >> myname;
	cout << "나이를 입력하세요 : ";
	cin >> myage;
	
	me.SetName(myname);
	me.SetAge(myage);

	me.GetName();
	me.GetAge();
}