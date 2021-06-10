#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//	vector<int> v;	// 배열같이 사용 가능
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
		cout << v[i] << ' ';	// 배열형태
	}

	cout << endl;

	for (auto iter = v.begin(); iter < v.end(); iter++)
	{
		cout << *iter << ' ';	// 포인터가 가르키고있는 값의 데이터를 읽어옴
	}

	cout << endl;

	for (auto i = v.begin(); i < v.end(); i++)
	{
		cout << *i << ' ';	// 포인터가 가르키고있는 값의 데이터를 읽어옴
	}

	return 0;
}