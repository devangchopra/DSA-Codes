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
void helper(treenode* root,vector<int>&v)
{
    if(root==NULL) return;
    v.push_back(root->data);
    helper(root->left,v);
    helper(root->right,v);
}
void printpairs(treenode* root,int s)
{
    if(root==NULL) return;
    std::vector<int> v;
    helper(root,v);
    sort(v.begin(),v.end());
    int i=0;
    int j=v.size()-1;
    while(i<j)
    {
        if(v[i]+v[j]==s)
        {
            cout<<v[i]<<" "<<v[j]<<endl;
            i++;
            j--;
        }
        else if(v[i]+v[j]>s)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

}

int main()
{
    treenode* root=takeinput();
    int s;
    cin>>s;
    printpairs(root,s);
}
