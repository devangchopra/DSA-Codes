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
queue<TreeNode*>pendingnodes;
int countnodes(TreeNode* root)
{
    TreeNode* temp=root;
    for (int i=0;i<temp->children.size();i++)
    {
        countnodes(temp->children[i]);
        pendingnodes.push(temp->children[i]);

    }
   
    return (pendingnodes.size()+1);
}
int main()
{
    TreeNode* root=inpput();
    cout<<countnodes(root);
}