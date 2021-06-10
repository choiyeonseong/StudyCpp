#include<string>
#include<iostream>
#include<memory>
using namespace std;

int main()
{
	auto_ptr<string>pStr(new string("AutoPtr Test"));
	// 문자열 객체도 auto_ptr로 감싸두면 스택의 래퍼 객체가 파괴될때
	// string이 할당한 메모리가 자동으로 해제된다.

	cout << *pStr << endl;
}