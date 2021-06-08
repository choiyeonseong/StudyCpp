#include<iostream>
using namespace std;

void TestFunc1()
{
	cout << "TestFunc1() START" << endl;
	//throw 0;	// 에러 발생
	cout << "TestFunc1() END" << endl;
}
void TestFunc2()
{
	cout << "TestFunc2() START" << endl;
	//TestFunc1();
	throw 0;
	cout << "TestFunc2() END" << endl;
}
void TestFunc3()
{
	cout << "TestFunc3() START" << endl;
	TestFunc2();
	cout << "TestFunc3() END" << endl;
}

int main()
{
	try {
		TestFunc3();
	}
	catch(...){	// 어떤 것이라도 다 받음
		cout << "Exception Handling" << endl;
	}
	TestFunc1();

	return 0;
}
/* 스택풀기 : 함수를 반환하지않고 스택을 풀어버린다. */