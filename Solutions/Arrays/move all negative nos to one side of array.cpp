#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    int arr[k];
    for(int i=0;i<k;i++)
    {
        cin>>arr[i];
    }
    //your array contains positive as well as negative numbers
    int brr[k];
    int index=0;
    
    for(int i=0;i<k;i++)
    {
        if(arr[i]<0)
        {
            brr[index]=arr[i];
            index++;
        }
    }

    for(int i=0;i<k;i++)
    {
       if(arr[i]>0) 
       {
           brr[index]=arr[i];
           index++;
       }
        
                
    }
    //cout<<brr+1;//this will give address of brr
    //cout<<*brr;
    for(int i=0;i<k;i++)
    {
        cout<<brr[i]<<" ";
    }
}