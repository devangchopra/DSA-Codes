#include <bits/stdc++.h>
using namespace std;

vector<int>v;

void helper(vector<int>arr,int index,int data,int count)
{
	if(index==count)
	{
		return;
	}
	if(arr[index]==data)
	{
		v.push_back(index);
	}
	helper(arr,index+1,data,count);
	
}

vector<int> fxn(vector<int>arr,int index,int data,int count)
{

	helper(arr,index,data,count);
	return v;	
}

int main()
{
	vector<int>input{10,10,10,20,30,30,40};
	int index=0;
	int data=30;
	int n=7;

	vector<int> ans=fxn(input,0,data,n);
	for(auto i:ans)
	{
		cout<<i<<" ";
	}
	cout<<endl;

}