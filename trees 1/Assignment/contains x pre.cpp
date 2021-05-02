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


bool check_if_present(TreeNode* root , int x)
{ 
    if(root->data==x){return true;}
    for(int i=0;i<root->children.size();i++){check_if_present(root->children[i],x);}
    return false;
}
int main()
{
    TreeNode* root=takeinput();
    int x;
    cin>>x;
    cout<<check_if_present(root,x);
}