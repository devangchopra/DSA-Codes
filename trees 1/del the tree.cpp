#include<bits/stdc++.h>
using namespace std;
#include "header.cpp"
void deletetree(TreeNode* root)
{
    for (int i=0;i<root->children.size();i++)
    {
        deletetree(root->children[i]);
    }
    delete root;
}


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

int main()
{
    TreeNode* root = inpput();
    deletetree(root);
}
