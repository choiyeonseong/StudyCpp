/* Ŭ���� ���ø� */
#include<iostream>
using namespace std;

template <typename T>	// �Ϲ�ȭ
class CTest
{
private:
	T num;
public:
	// CTest(T anum) :num(anum) {}
	CTest(T);	// ������ ����
	void printData()
	{
		cout << "num : " << num << endl;
	}
};

// �ܺο��� ������ ���� - ����� �и�
template <typename T>	// �ܺο��� �����Ҷ��� ���ø� ������ �ѹ� �� �Ѵ�.
CTest<T>::CTest(T anum) {	// Ŭ���� �Ҽ��� ��Ÿ���� typename�� ��������Ѵ�.
	num = anum;
}

int main()
{
	//CTest obj(10);	// Ŭ���� ���ø������� Ÿ���� ����ؾ��Ѵ�.
	CTest<int> obj(10);

	obj.printData();

	return 0;
}