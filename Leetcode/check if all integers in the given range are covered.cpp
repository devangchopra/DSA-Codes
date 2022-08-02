#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        // int left 
                      // vector : L----R
        //int right 
        
       
        set<int>v;
        bool x=true;
        sort(ranges.begin(),ranges.end());
        int k=0;
        for(int i=left;i<=right;i++)
        {
            v.insert(i);
        }
        
        cout<<"Vector is : "<<endl;
        for(auto i:v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
        set<int>output;

        for(int i=0;i<ranges.size();i++)
        {
            int l=ranges[i][0];
            int r=ranges[i][1];
            for (int m = l; m <=r; ++m)
            {
                output.insert(m);
            }
        }


        cout<<endl;
        cout<<"Set is"<<endl;
        for(auto i:output)
        {
            cout<<i<<" ";
        }
        
        cout<<endl;

        for(auto i:v)
        {
            bool temp=false;
            for(auto e:output)
            {
                if(i==e)
                {
                    temp=true;
                    break;
                }
            }
            if(temp==false)
            {
                x=false;
                break;
            }
        }
        

        
        
        return x;
    }
};
int main()
{
    Solution obj;
   vector<vector<int>> ranges{{1,50}};
    int left=1;
    int right=50;
    cout<<obj.isCovered(ranges,left,right);

}