#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>pq;

        for(long long i=0;i<n;i++)
        {
        	pq.push(arr[i]);
        }
        long long sum=0;
        while(pq.size()>=2)
        {
        	long long x1=pq.top();
        	pq.pop();
        	long long x2=pq.top();
        	pq.pop();
        	sum+=x1+x2;
        	pq.push(x1+x2);
        }
        return sum;
    }
};
int main()
{
	Solution obj;
	long long arr[]={4, 3, 2, 6};
	long long n=4;
	cout<<obj.minCost(arr,n);

}