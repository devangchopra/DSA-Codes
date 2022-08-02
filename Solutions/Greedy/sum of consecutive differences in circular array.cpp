#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>v{1,2,3,4,5};
	int n=v.size();

	sort(v.begin(), v.end());

	vector<int>d;

	int i=0;
	int j=n-1;

	while(i<j)
	{
		d.push_back(v[i]);
		d.push_back(v[j]);
		i++;
		j--;		
	}

	if(n%2!=0)
	{
		//odd size array
		// 1 miss
		int x=floor(n/2);
		d.push_back(v[x]);
	}

	for(auto i:d)
	{
		cout<<i<<" ";
	}
	cout<<endl;

	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		sum=sum+abs(d[i]-d[i+1]);
	}
	sum=sum+abs(d[n-1]-d[0]);
	

	cout<<sum<<endl;
}