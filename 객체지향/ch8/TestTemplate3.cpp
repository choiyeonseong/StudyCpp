/* 클래스 템플릿 */
#include<iostream>
using namespace std;

template <typename T>	// 일반화
class CTest
{
private:
	T num;
public:
	// CTest(T anum) :num(anum) {}
	CTest(T);	// 생성자 선언
	void printData()
	{
		cout << "num : " << num << endl;
	}
};

// 외부에서 생성자 정의 - 선언과 분리
template <typename T>	// 외부에서 정의할때는 템플릿 선언을 한번 더 한다.
CTest<T>::CTest(T anum) {	// 클래스 소속을 나타낼때 typename을 적어줘야한다.
	num = anum;
}

int main()
{
	//CTest obj(10);	// 클래스 템플릿에서는 타입을 명시해야한다.
	CTest<int> obj(10);

	obj.printData();

	return 0;
}