#include <bits/stdc++.h>
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

pair<bool,int> helper(treenode* root)
{
	if(root==NULL)
	{
		pair<bool,int> p;
		p.first=true;
		p.second=0;

	}

	pair<bool,int> leftsubtree=helper(root->left);
	pair<bool,int> rightsubtree=helper(root->right);

	bool isbstleft=leftsubtree.first;
	int max_height_of_left=leftsubtree.second;

	bool isbstright=rightsubtree.first;
	int max_height_of_right=rightsubtree.second;


	pair<bool,int>p;	
	if(isbstleft and isbstright)
	{
		if(root->data>root->left->data and root->data<=root->right->data)
		{
			p.first=true;
		}
	}
	if(p.first)
	{
		int height=max(max_height_of_left,max_height_of_right)+1;
		p.second=height;
	}
	else
	{
		p.second=0;
		p.first=false;
	}
	return p;

}

void largestbst(treenode* root)
{
	pair<bool,int> p =helper(root);
	cout<<p.second;
}
int main(int argc, char const *argv[])
{
	treenode* root=takeinput();
	largestbst(root);
	return 0;
}