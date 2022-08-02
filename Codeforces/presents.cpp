#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* arr;
	arr = new int [n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int* brr;
	brr = new int [n];

	unordered_map<int, int>m;
	for (int i = 0; i < n; i++)
	{
		m[arr[i]] = i+1;
	}

	for (int i = 0; i < n; i++)
	{
		brr[i] = m[i+1];
	}
	for (int i = 0; i < n; i++)
	{
		cout << brr[i] << " ";
	}
	cout << endl;
}