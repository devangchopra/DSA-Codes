#include<bits/stdc++.h>
using namespace std;
#include"header.h"
pair<int,int> heightdiameter(BinaryTreeNode* root)
{
    if(root==NULL)
    {
        pair<int,int>l;
        l.first=0;
        l.second=0;
        return l;
    }

    //base condition

    pair<int,int> leftans=heightdiameter(root->left);
    pair<int,int> rightans=heightdiameter(root->right);

    //hypothesis

    //induction
    int ld=leftans.second;
    int lh=leftans.first;

    int rd=rightans.second;
    int rh=rightans.first;

    //diameter -> second.... height->first

    int height=1+max(lh,rh);
    int diameter=max(lh+rh,max(lh,rh));

    pair<int,int>p;
    p.first=height;
    p.second=diameter;
    return p;

}

int main()
{
    //BinaryTreeNode* root=//input;
    //cout
}