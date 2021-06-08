/* 함수 템플릿 */
#include<iostream>
using namespace std;

template <typename T>	// 일반화
T Add(T a, T b)
{
	return a + b;
}

template <>	// 특수화 : 특정한 타입에 대해서 동작될 수 있게 만든 것
const char* Add(const char* lstr, const char* rstr)
{
	int llen = strlen(lstr);
	int rlen = strlen(rstr);
	int len = llen + rlen + 1;	// 전체 문자열의 길이

	char* str = new char[len];	// 결과 값이 될 문자열
	strcpy_s(str, llen + 1, lstr);
	strcat_s(str, len, rstr);
	return str;
}

int main()
{
	cout << Add<int>(10, 20) << endl;
	cout << Add<double>(3.14, 2.5) << endl;
	cout << Add<const char*>("Hello", "World") << endl;

	return 0;
}