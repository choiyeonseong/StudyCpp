#include <stdio.h>
#include <string.h>

class Date
{
protected:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutDate() { printf("%d/%d/%d", year, month, day); }
};

class Product
{
private:
	char name[64];
	char company[32];
	Date validto;	// 포함 : 객체를 멤버로 선언하여 해당 클래스의 기능을 재활용
	int price;
public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) 
		: validto(y, m, d)	// 멤버를 일일이 선언할 필요없이 정보를 잘 캡슐화 해놓은 객체하나 선언하는게 더 간편하다
	{
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}
	void OutProduct() {
		printf("이름:%s\n", name);
		printf("제조사:%s\n", company);
		printf("유효기간:");
		validto.OutDate();
		puts("");
		printf("가격:%d\n", price);
	}
};

int main()
{
	Product shrimp("새우깡", "농심", 2020, 8, 15, 900);
	shrimp.OutProduct();
}

