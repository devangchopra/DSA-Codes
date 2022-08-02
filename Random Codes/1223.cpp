#include<bits/stdc++.h>
using namespace std;
class meetings
{
public:
	int position;
	int start_time;
	int end_time;
};
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	vector<meetings>v;

	int n;
	cin>>n;

	int s[n];
	int f[n];

	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}

	for(auto i:s)
	{
		cout<<i<<" ";
	}

	

	
	return 0;
}