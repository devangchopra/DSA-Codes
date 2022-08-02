#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int arr[x];
   
    for (int i=0;i<x;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    sort(arr,arr+x);
    /*for (int i=0;i<x;i++)
    {
        cout<<arr[i]<<" ";
    }*/

    cout<<arr[k-1];
    // time complexity of sort function is O(N(LOG(N))) or O(N^2) previous versions of c++
}
// math = min.math