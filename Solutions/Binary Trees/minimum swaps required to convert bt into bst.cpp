#include<bits/stdc++.h>
using namespace std;

void inorder(int a[],vector<int>&v , int n, int index)
{
    if(index>=n)
        return;
    inorder(a,v,n,2*index+1);
    v.push_back(a[index]);
    inorder(a,v,n,2*index+2);

}
int ans(vector<int>v)
{
    if(v.size()==0) return 0;
    vector<pair<int,int>>final;
    for(int i=0;i<v.size();i++)
    {
        final.push_back({v[i],i});
    }
    sort(final.begin(),final.end());
    int c=0;
    for(int i=0;i<final.size();i++)
    {
        if(final[i].second==i)
            //already agr positions theek hai to kuch krne ki jarrorat nhi hai
            continue;
        else
        {
            c++;
            swap(final[i],final[final[i].second]);
            i--;
            //Check is se hogya sorted
            // kya pta jo value swap hone ke baad ayaex(5,1) wo positionn shi hai ki nhi
        }    

    }
    return c;
}
int main()
{
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << ans(v) << endl;
    
}