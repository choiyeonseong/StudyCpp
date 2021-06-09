#include<iostream>
using namespace std;

class Base {
private:
	int data;
public:
	Base() {}
	~Base() {}
	void setData(int adata) { data = adata; }
	int getData() { return data; }
};
class Derived :public Base {
public:
	void setData(int adata) {
		if (adata > 0) adata = 0;
		Base::setData(adata);
	}
	void printData() {
		cout << "printData() : " << getData() << endl;
	}
};

int main()
{
	Base* pb = new Derived;	// 포인터 타입의 자료형을 따름
	Derived* pd = NULL;

	pb->setData(10);	// Base::setData() 호출
	//pb->printData();	// 에러

	pd = static_cast<Derived*>(pb);	// 정적 형변환 static_cast
	pd->setData(20);	// Derived::setData() 호출
	pd->printData();	

	return 0;
}