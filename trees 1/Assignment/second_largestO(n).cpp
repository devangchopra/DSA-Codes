#include<bits/stdc++.h>
using namespace std;
#include "header.cpp"

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
int first = INT_MIN, second  = INT_MIN;

void second_largests(TreeNode* root)
{
    v.push_back(root->data);
    if(root->data>first)
    {
      second = first;
      first = root->data;
    }
    // Equal because second largest can be equal to first largest(binary tree BUT not BST)
    // CASE of only one node is not handled.
    else if(first >= root->data and second < root->data) 
      second = root-> data;
    for(int i=0;i<root->children.size();i++) 
    {
        second_largests(root->children[i]);        
    }
}

int main()
{
    TreeNode* root=takeinput();
    second_largests(root);
    cout << second <<endl;
    
}
