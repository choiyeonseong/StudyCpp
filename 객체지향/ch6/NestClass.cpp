#include<stdio.h>
#include<string.h>

// 외부 클래스
class Product
{
private:
	char name[64];
	char company[32];
	int price;

	// 지역(내부) 클래스 선언
	class Date	// 외부에서 필요하지 않는다면 class내부에 선언
	{
	protected:
		int year, month, day;
	public:
		Date(int y, int m, int d) { year = y; month = m; day = d; }
		void OutDate() { printf("%d/%d/%d", year, month, day); }
	};

	Date validto;	// 포함기법과 유사하되 객체 뿐만아니라 클래스 선언문까지 포함

public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice)
		: validto(y, m, d)
	{
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}
	void OutProduct() {
		printf("이름:%s\n", name);
		printf("제조사:%s\n", company);
		printf("유효기간:");
		validto.OutDate();	// 상속 받은 부모 클래스의 함수를 호출
		puts("");
		printf("가격:%d\n", price);
	}
};

int main()
{
	Product shrimp("새우깡", "농심", 2020, 8, 15, 900);
	shrimp.OutProduct();

	//Date now(12,34,56);	// 지역클래스라서 main에서는 생성할 수 없음
	//Product::Date now(12, 34, 56);	//Date를 Product의 public 영역에 선언하면 이렇게 사용 가능
}