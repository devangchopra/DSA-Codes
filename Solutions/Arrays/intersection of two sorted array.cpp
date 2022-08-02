#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n];
    int brr[m];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<m;i++) cin>>brr[i];

    int i=0,j=0;
    vector<int>v;

    while (i<n and j<m)
    {
        if(arr[i]==brr[j])
        {
            v.push_back(arr[i]);
        }
        if(arr[i]<brr[j])
        {
            i++;
        }
        else{
            j++;
        }
    }
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";

}