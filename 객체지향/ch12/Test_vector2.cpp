#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a, int b) { return a > b; }	// 내림차순 정렬

int main()
{
	vector<int> arr;
	arr.push_back(7);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(6);

	sort(arr.begin(), arr.end());			// 오름차순 정렬
	sort(arr.begin(), arr.end(), compare);	// 내림차순 정렬

	for (auto i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}