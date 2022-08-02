#include <bits/stdc++.h>
using namespace std;
#define min_priority_queue priority_queue<int,vector<int>,greater<int>> 
int main()
{
	int t;
	cin>>t;
	min_priority_queue pq;

	while(t--)
	{
		int n;
		cin>>n;

		while(n--)
		{
			int i;
			cin>>i;
			pq.push(i);
		}
	}

	while(pq.empty()==false)
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}