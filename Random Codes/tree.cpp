#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node* left;
	node* right;

	node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
node* takeinput()
{
    int data;
    cin>>data;

    queue<node*>pendingqueue;
    node* temp=new node(data);
    pendingqueue.push(temp);

    while(pendingqueue.size()!=0)
    {
        node* front=pendingqueue.front();
        pendingqueue.pop();
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            node* left=new node(ld);
            front->left=left;
            pendingqueue.push(left);
        }
        int rd;
        cin>>rd;

        if(rd!=-1)
        {
       		node* right=new node(rd);
            front->right=right;
            pendingqueue.push(right);       

        }
        
    }
    return temp;
}
void helper(node* root, int n, vector<int>&path)
{
	//Base Case
	if(root==NULL)
		return;

	path.push_back(root->data);

	//Hypothesis
	helper(root->left,n,path);
	helper(root->right,n,path);

	//Induction
	int f=0;
	for(int j=path.size()-1;j>=0;j--)
	{
		f=f+path[j];
		if(j==n)
		{
			for(int m=j;m<path.size();m++)
			{
				cout<<path[m]<<" ";
			}
		}
		cout<<endl;
	}
	path.pop_back();

}
void sumkpaths(node* root,int n)
{
	vector<int>path;
	helper(root,n,path);
}
int main()
{
	node* root=takeinput();
	int n;
	cin>>n;
	sumkpaths(root,n);
}
