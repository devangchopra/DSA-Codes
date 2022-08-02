#include <bits/stdc++.h>
using namespace std;
int main()
{
	//Min heap
	priority_queue<int,vector<int>,greater<int>>pq;

	//Data Type , Internal Implementation with vector so write that,comperator

	pq.push(10);
	pq.push(20);
	pq.push(0);
	cout<<pq.top()<<endl;

}