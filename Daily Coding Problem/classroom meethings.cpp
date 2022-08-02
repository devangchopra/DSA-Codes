/*
This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures 
(possibly overlapping), find the minimum number of rooms required.
For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<int>arr;
	vector<int>brr;

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		arr.push_back(x);
	}

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		brr.push_back(x);
	}
	sort(arr.begin(),arr.end());
	sort(brr.begin(),brr.end());

	int n_class=1;
	int temp=1;

	int i=1 , j=0;
	while(i<n and j<n);
	{
		if(arr[i]<=brr[j])
		{
			temp++;
			i++;
		}
		else if(arr[i]>brr[j])
		{
			temp--;
			j++;
		}
		if(temp>n_class)
		{
			n_class=temp;
		}

	}
	cout<< n_class<<endl;
}