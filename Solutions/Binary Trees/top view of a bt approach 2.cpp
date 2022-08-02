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

    queue<treenode*>pendingqueue;
    treenode* temp=new treenode(data);
    pendingqueue.push(temp);

    while(pendingqueue.size()!=0)
    {
        treenode* front=pendingqueue.front();
        pendingqueue.pop();
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            treenode* left=new treenode(ld);
            front->left=left;
            pendingqueue.push(left);
        }
        int rd;
        cin>>rd;

        if(rd!=-1)
        {
            treenode* right=new treenode(rd);
            front->right=right;
            pendingqueue.push(right);       

        }
        
    }
    return temp;
}

void traverse(treenode* root,int d,map<int,vector<int>>&m)
{
    if(root==NULL)
    {
        return;
    }
    if(m[d].size()<1)
    {
        m[d].push_back(root->data);
    }
    traverse(root->left,d-1,m);
    traverse(root->right,d+1,m);
}

void topview(treenode* root)
{
    if(root==NULL)
    {
        return;
    }
    map<int,vector<int>>m;
    int d=0;
    traverse(root,d,m);

    for(auto p:m)
    {
        vector<int>line=p.second;
        for(auto i : line)
        {
            cout<<i<<" ";
        }
        
    }


}


int main()
{
    treenode* root=takeinput();
    topview(root);
}