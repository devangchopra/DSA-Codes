#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v {10, 15, 3, 7};

	int k=17;

	sort(v.begin(),v.end()); //o(nlogn)

	int i=0;
	int j=v.size()-1;

	bool x=false;

	while(i<j)
	{
		if(v[i]+v[j]<k)
		{
			i++;
		}
		else if(v[i]+v[j]>k)
		{
			j--;
		}
		else if(v[i]+v[j]==k)
		{
			x=true;
			break;
		}

	}
	cout<<x<<'\n';
}