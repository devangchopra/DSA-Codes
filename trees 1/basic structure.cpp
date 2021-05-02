#include<bits/stdc++.h>
using namespace std;
class TreeNode    //defining our own data type
{
    public:

        int data;
        vector<TreeNode*>children;

    TreeNode(int data)
    {
        this->data=data;
    }
};



int main()
{
    //static creation
    TreeNode root(10);
    TreeNode c1(20);
    TreeNode c2(30);
    root.children.push_back(&c1); //&==address
    root.children.push_back(&c1);
    
}
