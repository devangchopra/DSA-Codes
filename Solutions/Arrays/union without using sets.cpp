#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n],brr[m];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for (int j=0;j<m;j++)
    {
        cin>>brr[j];
    }
    // inputted both the arrays
    int x;
    if(n>m)
        x=n;
    else
        x=m;
    int frequency [x]={0};//larger
    
    for (int i=0;i<n;i++)
    {
        frequency[arr[i]]++;   
    }
    int count=0;
    for (int j=0;j<m;j++)
    {
        frequency[brr[j]]++;
    }
    for (int i=0;i<x;i++)
    {
        if(frequency[i]!=0)
        {
            count++;
        }
    }
    cout<<count;
}