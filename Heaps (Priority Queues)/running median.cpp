#include <bits/stdc++.h>
using namespace std;
#define min_priority_queue  priority_queue<int,vector<int>,greater<int>> 

void median(vector<int> arr,int n)
{
    priority_queue<int> max;
    min_priority_queue min;

    int median=arr[0];
    max.push(arr[0]);
    cout<<median<<endl;

    for(int i=1;i<n;i++)
    {
        int x=arr[i];

        //Left 
        if(max.size()>min.size())
        {
            if(x<median)
            {
                min.push(max.top());
                max.pop();
                max.push(x);
            }
            else
            {
                min.push(x);
            }
            median=(min.top()+max.top())/2.0;
        }

        //Right
        else if(max.size()<min.size())
        {
            if(x>median)
            {
                max.push(min.top());
                min.pop();
                min.push(x);
            }
            else
            {
                max.push(x);
            }
            median=(min.top()+max.top())/2.0;

        }

        //Equal
        else
        {
            if(x<median)
            {
                max.push(x);
                median=max.top();
            }
            else
            {
                min.push(x);
                median=min.top();
            }
        }
        cout<<median<<endl;
    }
}

int main()
{
    vector<int> arr{5,4,3,2,1};
    int n=arr.size();
    median(arr,n);
}