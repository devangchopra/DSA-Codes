#include<bits/stdc++.h>
#include "header.cpp"

TreeNode* takeinput()
{
    int data;
    cout<<"Enter The Data";
    //will consider this as a root
    cin>>data;
    TreeNode* root=new TreeNode(data);
    int n;
    cout<<"Enter Number Of childrens of"<<data<<" ";
    cin>>n;

    for (int i=0;i<n;i++)
    {
        TreeNode* child=takeinput();
        root->children.push_back(child);
        //making connections
    }
    return root;
}

void printtree(TreeNode* root)
{
    TreeNode* temp=root;
    if(temp==NULL)
    {
       return;
    }
    cout<<temp->data<<"->";
    
    for (int i=0;i<temp->children.size();i++)
    {
        cout<<temp->children[i]->data;
        
    }
    cout<<endl;
    for (int i=0;i<temp->children.size();i++)
    {
        printtree(temp->children[i]);
    }
}



int main()
{
    TreeNode* root= takeinput();
    printtree(root);

}