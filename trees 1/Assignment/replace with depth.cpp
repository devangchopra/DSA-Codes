#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:

        int data;
        vector<TreeNode*>children;

    TreeNode(int data)
    {
        this->data=data;
    }
};

TreeNode* takeinput()
{
    int data;
    cin>>data;
    TreeNode* temp=new TreeNode(data);
    queue<TreeNode*>pendingnodes;
    pendingnodes.push(temp);
    while(pendingnodes.size()!=0)
    {
        TreeNode* front=pendingnodes.front();
        pendingnodes.pop();
        int nch;
        cin>>nch;
        for(int i=0;i<nch;i++)
        {
            int data;
            cin>>data;
            TreeNode* child=new TreeNode(data);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return temp;
}

void printtree(TreeNode* root)
{
    
    TreeNode* temp=root;
    queue<TreeNode*>pendingnodes;
    pendingnodes.push(temp);

    while(pendingnodes.size()!=0)
    {
        TreeNode* front=pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<" :"<<" ";
        for(int i=0;i<front->children.size();i++)
        {
            cout<<front->children[i]->data<<" ";
            pendingnodes.push(front->children[i]);
        }
        cout<<endl;
    }   
}

void ans(TreeNode* root , int k)
{
    root->data=k;
    for(int i=0;i<root->children.size();i++)
    {
        ans(root->children[i],k+1);
    }

}

void replace_with_depth(TreeNode* root)
{
    int k=0; 
    ans(root,k);
}
int main()
{
    TreeNode* root=takeinput();
    cout<<"Befor replacement"<<endl;
    printtree(root);
    cout<<"After replacement"<<endl;
    replace_with_depth(root);
    printtree(root);
}