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
