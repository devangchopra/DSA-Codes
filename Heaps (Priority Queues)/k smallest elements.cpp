#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>arr {5,6,9,12,3,13,2};
	int n=arr.size();

	int k=3;

	priority_queue<int>pq; //max heap

	for(int i=0;i<k;i++)
	{
		pq.push(arr[i]);
	}

	//Travel in array outside heap

	for(int i=k+1;i<n;i++)
	{
		if(pq.top()>arr[i])
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}

	while(pq.empty()==false)
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
}