/*
	가상 소멸자
	포인터의 정적 타입에 따라 소멸자가 정적으로 결합되기때문에
	소멸자를 가상함수로 만들어서 동적 결합 되게 한다.
*/

#include<iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int anum) {
		num = anum;
		cout << num << " CTest constructor" << endl;
	}
	virtual ~CTest() {
		cout << num << " CTest deconstructor" << endl;
	}
	virtual void func() {
		cout << "CTest fucntion()" << endl;
	}
};

class CTestSub :public CTest
{
private:	// default
	int subN;
public:
	CTestSub(int anum, int asubN) :CTest(anum) { 
		subN = asubN;
		cout << subN << " CTestSub constructor" << endl;
	}
	virtual ~CTestSub() {
		cout << subN << " CTestSub deconstructor" << endl;
	}
	void func()
	{
		cout << "CTestSub function()" << endl;
	}
};

int main()
{
	CTest b(10);
	b.func();
	
	CTestSub d(20, 30);
	d.func();
	
	CTest* pb = new CTestSub(40, 44);	// 추상자료형으로 자식객체를 가리키게한다.

	pb->func();	// CTest::func()이 호출됨
				// virtual이 되면 CTestSub::func()이 호출됨

	delete pb;	// CTest소멸자만 호출되고 CTestSub소멸자는 호출 안됨
				// 가상 소멸자를 생성하면 CTestSub소멸자도 실행됨
	return 0;
}