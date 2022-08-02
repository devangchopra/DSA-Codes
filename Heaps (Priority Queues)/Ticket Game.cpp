#include <bits/stdc++.h>
using namespace std;
int buyTicket (int input[], int n, int k){
    queue<int> q;
    // Max priority queue 
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        q.push(input[i]);
        pq.push(input[i]);
    }
    int count = 0;
    while(!pq.empty()) { 
        if(q.front() == pq.top()) { 
            if(k == 0) {
                return count + 1;
            } 
            else {
                count++; 
                q.pop(); 
                pq.pop(); 
                k--;
            }
        }
        else {
            q.push(q.front()); 
            q.pop();
            if(k == 0) {
                k = q.size() - 1;
            }
            else { 
                k--;
            }
        }
    }
    return count;
}
int main()
{
	int arr[]={2 ,3 ,2 ,2 ,4};
	int n=5;
	int k=3;
	cout<<buyTicket(arr,n,k);
}
