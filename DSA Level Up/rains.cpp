#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> arr{0,1,0,2,1,0,1,3,2,1,2,1};

	vector<int> left_arr;
	vector<int> right_arr;

	int left_max=arr[0];

	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]>left_max)
		{
			left_max=arr[i];
		}
		left_arr.push_back(left_max);
	}

	int right_max=arr[arr.size()-1];

	for(int i=arr.size()-1;i>=0;i--)
	{
		if(arr[i]>right_max)
		{
			right_max=arr[i];
		}
		right_arr.push_back(right_max);
	}
	reverse(right_arr.begin(),right_arr.end());

	/*

	for(auto i:left_arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;

	for(auto i:right_arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;

	*/

	int count =0;

	for(int i=0;i<arr.size();i++)
	{
		count+=min(left_arr[i],right_arr[i])-arr[i];
	}
	cout<<count<<endl;
	
}