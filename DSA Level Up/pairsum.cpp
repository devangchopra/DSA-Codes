#include<bits/stdc++.h>
using namespace std;
void pairs(vector<int> v, int k)
{
	unordered_set <int> s;
	for(auto i:v)
	{
		int x=k-i;
		if(s.find(x)!=s.end())
		{
			cout<<i<<" "<<x;
			return;
		}
		s.insert(i);
	}
}
int main()
{
	vector<int>v;
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	int k;
	cin>>k;
	pairs(v,k);
}