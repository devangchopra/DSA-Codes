#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll x;
    cin>>x;
    ll arr[x];
    for (ll i=0;i<x;i++)
    {
        cin>>arr[i];
    }
    ll p1=0;    
    ll p2=(x-1); 
    
    int sum;
    cin>>sum;
    sort(arr,arr+x);
    while(p1<p2)
    {
        if (arr[p1]+arr[p2]==sum)
        {
            cout<<p1<<" "<<p2; 
            break;
        }
        else if (arr[p1]+arr[p2]<sum)
        {   
            p1++;
                      
        }
        else
        {
            p2--;
        }
    }
}