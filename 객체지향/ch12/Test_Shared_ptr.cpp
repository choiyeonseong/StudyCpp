#include<iostream>
using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest" << endl; }
	~CTest() { cout << "~CTest" << endl; }
	void func() { cout << "func()" << endl; }
};
int main()
{
	
	shared_ptr<CTest> ptr1(new CTest);	// �ټ����� �޸� ���� �Ҵ� ����, �����Ҵ�� �������� Ƚ�� ���(use_count)
	ptr1->func();
	cout << "count: " << ptr1.use_count() << endl;	// 1

	{
		shared_ptr<CTest> ptr2(ptr1);	// ptr1�� ����
		cout << "count: " << ptr1.use_count() << endl;	// 2

		ptr2->func();
	}	// ����� �������� ���� ptr2 ���� �Ҵ� ����

	cout << "count: " << ptr1.use_count() << endl;	// 1

	//ptr2->func();	// ���� �Ұ� - �ڵ����� �޸� ���� �Ҵ��� �����Ǿ���
	ptr1 ->func();
	

	//unique_ptr<CTest> ptr1(new CTest);

	return 0;
}