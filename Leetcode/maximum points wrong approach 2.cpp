#include<bits/stdc++.h>
using namespace std;
int maxScore(vector<int>& cardPoints, int k) {
    if(k==cardPoints.size())
    {
        int ans=0;
        for(int i=0;i<cardPoints.size();i++)
        {
            ans=ans+cardPoints[i];
        }
        return ans;
    }

    int s=0;
    int e=cardPoints.size()-1;
    int ans=0 ,counter=1;
    for(int i=0;i<cardPoints.size();i++)
    {
        if(counter<=k)
        {
            counter++;
            int x=cardPoints[s];
            int y=cardPoints[e];
            int temp=max(x,y);
            if(temp==x)
            {
                s++;
            }
            if(temp==y)
            {
                e--;
            }
            ans+=temp;

        }
    }
    return ans;




}  
int main()
{

   std::vector<int> v={100,40,17,9,73,75};
   cout<<maxScore(v,3);
}
