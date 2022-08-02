#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    // we dont want to print anything first
    int x;
    cin>>x;
    int arr[x];
    for (int i=0 ;i<x;i++)
    {
        cin>>arr[i];
    }
    int max = arr[0];
    int min=arr[1];
    for (int i=0 ;i<x;i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min = arr[i];
        }
    }
    cout<<"Minimum"<<min<<" "<<"Mximum"<<max;

}