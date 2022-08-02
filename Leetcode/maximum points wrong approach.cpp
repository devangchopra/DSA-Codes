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

    vector<int> left; 
    vector<int> right;

    for(int i=0;i<k;i++)
    {
        left.push_back(cardPoints[i]);
    }

    for(int i=cardPoints.size()-1;i>=k;i--)
    {
        right.push_back(cardPoints[i]);
    }

    //for(int i=0;i<k;i++) cout<<left[i]<<" ";
    //cout<<endl<<endl;
    //cout<<"this is second"<<endl;

    //for(int i=0;i<k;i++) cout<<right[i]<<" ";

    int lsum=0;
    int rsum=0;
    for(int i=0;i<k;i++) lsum=lsum+left[i];
    for(int i=0;i<k;i++) rsum=rsum+right[i];
    return max(lsum,rsum);  
       

}  
int main()
{

   std::vector<int> v={1,2,3,4,5,6,1};
   cout<<maxScore(v,3);
}
