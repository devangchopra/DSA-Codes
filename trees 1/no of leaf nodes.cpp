#include<bits/stdc++.h>
#include "header.cpp"
using namespace std;
TreeNode* inpput()
{
    int rootdata;
    cout<<"Enter root data";
    cin>>rootdata;

    TreeNode* root= new TreeNode(rootdata);
    queue<TreeNode*> pendingnodes;

    pendingnodes.push(root);

    //using a queue to keep a track

    while(pendingnodes.size()!=0)
    {
        TreeNode* temp=pendingnodes.front();
        // poping out the first element of queue

        pendingnodes.pop() ;//remove

        int c;
        cout<<"Enter no. of childs of"<<temp->data<<" ";
        cin>>c;

        for (int i=0;i<c;i++)
        {
            int cdata;
            cout<<"Enter"<<i<<" "<<"child's"<<" "<<"data";
            cin>>cdata;

            TreeNode* child=new TreeNode(cdata);
            temp->children.push_back(child);

            pendingnodes.push(child);
        }

    }
    return root;

}
void printtree(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    TreeNode* temp=root;
    //never play and loose original root cause its a pointer
    cout<<temp->data<<":";
    for (int i=0;i<temp->children.size();i++)
    {
        cout<<temp->children[i]->data<<" ";
    }
    cout<<endl;
    for (int i=0;i<temp->children.size();i++)
    {
        printtree(temp->children[i]);//minitree
    }
}
int numberofleafnodes(TreeNode* root)
{
    int count=0;
    
    if(root->children.size()==0)
    {
        return 1;
    }
    for (int i=0;i<root->children.size();i++)
    {
        
        count+=numberofleafnodes(root->children[i]);
    }
    
    return count;
}

int main()
{
    TreeNode* root=inpput();
    printtree(root);
    cout<<numberofleafnodes(root);
}
