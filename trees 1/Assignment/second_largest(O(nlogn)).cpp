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

vector<int>v;
void second_largests(TreeNode* root)
{
    
    v.push_back(root->data);
    for(int i=0;i<root->children.size();i++) 
    {
        second_largests(root->children[i]);        
    }
  
    
}

int main()
{
    TreeNode* root=takeinput();
    second_largests(root);
    sort(v.begin(),v.end());
    int x=v.size();
    cout<<v[x-2];
}