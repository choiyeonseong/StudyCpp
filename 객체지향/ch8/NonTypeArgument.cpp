#include<stdio.h>

// 임의의 타입에 대해 임의 크기를 지원하는 안전 배열을 만든다.
template<typename T, int N>	// N은 비타입 인수
class Array
{
private:
	T ar[N];
public:
	void SetAt(int n, T v) { if (n < N && n >= 0)ar[n] = v; }
	T GetAt(int n) { return (n < N&& n >= 0 ? ar[n] : 0); }
};

int main()
{
	Array<int, 5> ari;
	ari.SetAt(1, 1234);
	ari.SetAt(1000, 5678);
	printf("%d\n", ari.GetAt(1));
	printf("%d\n", ari.GetAt(5));
}