#include<string>
#include<iostream>
#include<memory>
using namespace std;

int main()
{
	auto_ptr<string>pStr(new string("AutoPtr Test"));
	// ���ڿ� ��ü�� auto_ptr�� ���εθ� ������ ���� ��ü�� �ı��ɶ�
	// string�� �Ҵ��� �޸𸮰� �ڵ����� �����ȴ�.

	cout << *pStr << endl;
}