/*
	���� �Ҹ���
	�������� ���� Ÿ�Կ� ���� �Ҹ��ڰ� �������� ���յǱ⶧����
	�Ҹ��ڸ� �����Լ��� ���� ���� ���� �ǰ� �Ѵ�.
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
	
	CTest* pb = new CTestSub(40, 44);	// �߻��ڷ������� �ڽİ�ü�� ����Ű���Ѵ�.

	pb->func();	// CTest::func()�� ȣ���
				// virtual�� �Ǹ� CTestSub::func()�� ȣ���

	delete pb;	// CTest�Ҹ��ڸ� ȣ��ǰ� CTestSub�Ҹ��ڴ� ȣ�� �ȵ�
				// ���� �Ҹ��ڸ� �����ϸ� CTestSub�Ҹ��ڵ� �����
	return 0;
}