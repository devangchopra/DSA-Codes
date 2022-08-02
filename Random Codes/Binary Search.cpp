#include<bits/stdc++.h>
using namespace std;
int fun(int* arr,int n,int s,int e,int key)
{
  while(s<=e)
  {
    int mid = e+(s-e)/2;
    if(arr[mid]==key)
    {
      return mid;
    }
    else if(arr[mid]>key)
    {
      e=mid-1;
    }
    else
    {
      s=mid+1;
    }
  }
  return -1;
}
int main()
{
  int arr[]={2,3,5,6,7,8,9,22};
  int n = sizeof(arr)/sizeof(arr[0]);
  int s = 0;
  int e = n-1;
  int key;
  cin>>key;

  int ans = fun(arr,n,s,e,key);
  if(ans!=-1)
  {
    cout<<ans<<endl;
  }
  else
  {
    cout<<"Not Found"<<endl;
  }
}