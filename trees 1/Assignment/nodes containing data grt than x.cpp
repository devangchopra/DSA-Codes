#include<bits/stdc++.h>
#include "header.cpp"
using namespace std;
TreeNode* takeinput()
{
    int data;
    cin>>data;

    TreeNode* root=new TreeNode(data);
    
    queue<TreeNode*>pendingnodes;
    pendingnodes.push(root);

    while(pendingnodes.size()!=0)
    {
        TreeNode* front=pendingnodes.front();
        pendingnodes.pop(); 

        int child;
        cin>>child;
        for (int i=0;i<child;i++)
        {
            

            int data_c;
            cin>>data_c;

            TreeNode* temp=new TreeNode(data_c);
            pendingnodes.push(temp);
            front->children.push_back(temp);
        }
    }
    return root;
}
int check(TreeNode* root,int x)
{
    int count =0;
    if(root->data>x)
    {
        count++;
    }
    for(int i=0;i<root->children.size();i++)
    {
        count=count+check(root->children[i],x);
    }
    return count;
}

int main()
{
    TreeNode* root=takeinput();
    int x;
    cin>>x;
    cout<<check(root,x);
}