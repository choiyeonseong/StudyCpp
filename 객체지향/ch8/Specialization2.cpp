#include<stdio.h>
#include<iostream>
#include<cursor.h>
using namespace std;

template<typename T>	// Ŭ������ �Ϲ�ȭ�Ǿ��ִ� ���ø�
class PosValue
{
private:
	int x, y;
	T value;
public:
	PosValue(int ax, int ay, T av) :x(ax), y(ay), value(av) {}
	void outvalue()
	{
		gotoxy(x, y);
		cout << value << endl;
	}
};

// Ư��ȭ�� Ŭ������ Ÿ���� �̹� �����Ǿ� �־� Ÿ�� �μ� T�� �����ʰ� Ư��ȭ�� Ÿ���� Ŭ���� ���ǹ��� �ٷ� ���
template<>class PosValue<double>	// Ŭ���� ���ø� Ư��ȭ
{
private:
	int x, y;
	double value;
public:
	PosValue(int ax, int ay, double av) :x(ax), y(ay), value(av) {}
	void outvalue() 
	{
		gotoxy(x, y);
		cout << "[" << value << "]" << endl;
	}
};

int main()
{
	PosValue<int> iv(10, 10, 2);
	PosValue<char> cv(25, 5, 'C');
	PosValue<double> dv(30, 15, 3.14);
	iv.outvalue();
	cv.outvalue();
	dv.outvalue();
}
