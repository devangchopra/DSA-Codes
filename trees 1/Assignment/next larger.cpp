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
        int numchild;
        cin>>numchild;
        for (int i=0;i<numchild;i++)
        {
            int doc;
            cin>>doc;
            TreeNode* child=new TreeNode(doc);
            front->children.push_back(child);
            pendingnodes.push(child);

        }
    }
    return root;
}

int check(TreeNode* root, int n)
{
    TreeNode* temp=root;
    queue<TreeNode*>pendingnodes;
    pendingnodes.push(temp);

    int max=n;

    while(pendingnodes.size()!=0)
    {
        TreeNode* front=pendingnodes.front();
        pendingnodes.pop();

        int temp;
       // if(front->data>n)
        //{
            temp=front->data;
       // }

        for (int i=0;i<front->children.size();i++)
        {
            pendingnodes.push(front->children[i]);
        }
        if(temp>max)
        {
            max=temp;
            break;
        }

    }
    return max;
}


int main()
{
    TreeNode* root=takeinput();
    int x;
    cin>>x;
    int ans=check(root,x);
    cout<<ans<<endl;
    if(ans!=0)
    {
        cout<<ans<<endl;
    }
    else{
        cout<<"NULL"<<endl;
    }
}