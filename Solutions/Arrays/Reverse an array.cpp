#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int arr[x];
    int brr[x];
    for (int i=0;i<x;i++)
    {
        cin>>arr[i];
    }
    int m=0;
    for (int i=x-1;i>=0;i--)
    {
        brr[m]=arr[i];
        m++;
    }
      for (int i=0;i<x;i++)
    {
        cout<<brr[i]<<" ";
    }

}