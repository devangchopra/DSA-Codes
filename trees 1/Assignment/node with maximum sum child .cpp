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

int maxsumchild(TreeNode* root)
{
    TreeNode* temp=root;
    queue<TreeNode*>pendingnodes;
    pendingnodes.push(root);

    int node=root->data; //i say root data is max
    int max=0;             // i say lets say max =0

    while(pendingnodes.size()!=0)
    {
        TreeNode* front = pendingnodes.front();
        pendingnodes.pop();
        
        int x;
        x=root->data;
        for(int i=0;i<front->children.size();i++)
        {
            x=x+(front->children[i]->data);
            pendingnodes.push(front->children[i]);
        }
        if(max<x)
        {
            max=x;
            node=front->data;
        }
    }
    return node;
}
int main()
{
    TreeNode* root=takeinput();
    cout<<maxsumchild(root);
}