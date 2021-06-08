/* �Լ� ���ø� */
#include<iostream>
using namespace std;

template <typename T>	// �Ϲ�ȭ
T Add(T a, T b)
{
	return a + b;
}

template <>	// Ư��ȭ : Ư���� Ÿ�Կ� ���ؼ� ���۵� �� �ְ� ���� ��
const char* Add(const char* lstr, const char* rstr)
{
	int llen = strlen(lstr);
	int rlen = strlen(rstr);
	int len = llen + rlen + 1;	// ��ü ���ڿ��� ����

	char* str = new char[len];	// ��� ���� �� ���ڿ�
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