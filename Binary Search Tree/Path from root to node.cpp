#include<bits/stdc++.h>
using namespace std;
class treenode
{
    public:
    int data;
    treenode* left;
    treenode* right;

    treenode(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
treenode* takeinput()
{
    int data;
    cin>>data;
    queue<treenode*>q;
    treenode* root=new treenode(data);
    q.push(root);
    while(q.size()!=0)
    {
        treenode* temp=q.front();
        q.pop();
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            treenode* n=new treenode(ld);
            temp->left=n;
            q.push(n);
        }
        int rd;
        cin>>rd;
        if(rd!=-1)
        {
            treenode* n=new treenode(rd);
            temp->right=n;
            q.push(n);
        }
    }
    return root;
}

vector<int>* getRootToNodePath(treenode* root,int x)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==x)
    {
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    
    auto leftoutput=getRootToNodePath(root->left,x);

    if(leftoutput!=NULL)
    {
        leftoutput->push_back(root->data);
        return leftoutput;
    }

    auto rightoutput=getRootToNodePath(root->right,x);
    if(rightoutput!=NULL)
    {
        rightoutput->push_back(root->data);
        return rightoutput;
    }
    else{
        return NULL;
        //didnt found
    }

}
int main()
{
    treenode* root=takeinput();
    int x;
    cin>>x;
    auto final=getRootToNodePath(root,x);
    for(int i=0;i<final->size();i++)
    {
        cout<<final->at(i)<<" ";
    }
}