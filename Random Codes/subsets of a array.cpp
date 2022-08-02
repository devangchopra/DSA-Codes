#include <bits/stdc++.h>
using namespace std;

///SIMPLE


void fun(vector<int>v,vector<int>&ans)
{
	//Generate all subsets
	for(auto i:ans)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	
	for(auto i:v)
	{
		ans.push_back(i);
		fun(v,ans);
	}
	

}

int main()
{
	vector<int> v {1,2,3};
	vector<int>ans;
	fun(v,ans);
	return 0;
}