#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int>v;
	//vector<data type of elements>vector_name
	v={7,8,9,4,5,6,2,3};
	
	v.push_back(154678);
	v.push_back(25);
	v.pop_back();
	
	//sort(arr,arr+n) // arrays
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}

}