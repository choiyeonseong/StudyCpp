#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//	vector<int> v;	// �迭���� ��� ����
	//
	//	vector<int> v1 = { 1,2,3,4,5 };
	//	vector<int> v2[5];
	//
	//	v.push_back(10);
	//	vector<int> ::iterator iter = v.begin();
	//	iter = v.insert(iter, 2);
	//
	//	v.pop_back();
	//	v.erase(v.begin() + 10);

	vector<int> v = { 10,20,30,40,50 };
	for (auto i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';	// �迭����
	}

	cout << endl;

	for (auto iter = v.begin(); iter < v.end(); iter++)
	{
		cout << *iter << ' ';	// �����Ͱ� ����Ű���ִ� ���� �����͸� �о��
	}

	cout << endl;

	for (auto i = v.begin(); i < v.end(); i++)
	{
		cout << *i << ' ';	// �����Ͱ� ����Ű���ִ� ���� �����͸� �о��
	}

	return 0;
}