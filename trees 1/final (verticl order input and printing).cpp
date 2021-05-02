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

void printt(TreeNode* root)
{

    TreeNode* temp=root;

    queue<TreeNode*>pendingnodes;
    pendingnodes.push(root);
    cout<<temp->data<<endl;
    
    while(pendingnodes.size()!=0)
    {
        TreeNode* front = pendingnodes.front();
        pendingnodes.pop();
       
        
        for(int i=0;i<front->children.size();i++)
        {
            cout<<front->children[i]->data<<" ";
            pendingnodes.push(front->children[i]);
        }
        cout<<endl;
    }
}
int main()
{
    TreeNode* inp=inpput();
    printt(inp);
}
