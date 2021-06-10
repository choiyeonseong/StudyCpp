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
	
	shared_ptr<CTest> ptr1(new CTest);	// 다수개의 메모리 동적 할당 가능, 동적할당된 포인팅의 횟수 계산(use_count)
	ptr1->func();
	cout << "count: " << ptr1.use_count() << endl;	// 1

	{
		shared_ptr<CTest> ptr2(ptr1);	// ptr1을 복사
		cout << "count: " << ptr1.use_count() << endl;	// 2

		ptr2->func();
	}	// 블록을 빠져나온 순간 ptr2 동적 할당 해제

	cout << "count: " << ptr1.use_count() << endl;	// 1

	//ptr2->func();	// 접근 불가 - 자동으로 메모리 동적 할당이 해제되었음
	ptr1 ->func();
	

	//unique_ptr<CTest> ptr1(new CTest);

	return 0;
}