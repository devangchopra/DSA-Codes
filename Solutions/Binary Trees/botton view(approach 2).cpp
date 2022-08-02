#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:

	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
Node* takeinput()
{
    int data;
    cin>>data;

    queue<Node*>pendingqueue;
    Node* temp=new Node(data);
    pendingqueue.push(temp);

    while(pendingqueue.size()!=0)
    {
       Node* front=pendingqueue.front();
        pendingqueue.pop();
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            Node* left=new Node(ld);
            front->left=left;
            pendingqueue.push(left);
        }
        int rd;
        cin>>rd;

        if(rd!=-1)
        {
            Node* right=new Node(rd);
            front->right=right;
            pendingqueue.push(right);       

        }
        
    }
    return temp;
}

void traverse(Node* root,int d,map<int,vector<int>>&m)
{
    if(root=NULL)
    {
        return;
    }
    m[d].push_back(root->data);
    traverse(root->left,d-1,m);
    traverse(root->right,d+1,m);
}
void bottomView(Node *root)
{
   // Your Code Here
   if(root==NULL) return;
   
   //Vertcal Order
   map<int,vector<int>>m;
   int d=0;
   traverse(root,d,m);
   for(auto p:m)
   {
       vector<int>s=p.second;
       cout<<s[s.size()-1]<<" ";
   }
   
}
int main()
{
    Node* root=takeinput();
    bottomView(root);
}
