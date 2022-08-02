#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str="geeksforgeeks";
    
    int frequency[128]={0};
    for(int i=0;i<x;i++)
    {
        frequency[int(str[i])]++;
    }
    for(int i=0;i<128;i++)
    {
        if(frequency[i]>1)
        {
            cout<<"frequency of "<<char(i)<<"is"<<frequency[i];
        }
    }



}