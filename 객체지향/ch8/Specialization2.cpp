#include<stdio.h>
#include<iostream>
#include<cursor.h>
using namespace std;

template<typename T>	// 클래스의 일반화되어있는 템플릿
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

// 특수화된 클래스는 타입이 이미 결정되어 있어 타입 인수 T를 쓰지않고 특수화된 타입을 클래스 정의문에 바로 사용
template<>class PosValue<double>	// 클래스 템플릿 특수화
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
