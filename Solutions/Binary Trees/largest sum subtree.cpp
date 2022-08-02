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
    //cout<<"Enter Data"<<" :";
    cin>>data;

    queue<Node*>pendingqueue;
    Node* temp=new Node(data);
    pendingqueue.push(temp);

    while(pendingqueue.size()!=0)
    {
        Node* front=pendingqueue.front();
        pendingqueue.pop();

        int ld;
        //cout<<"Enter Left Child"<<" ";
        cin>>ld;

        if(ld!=-1)
        {
            Node* left=new Node(ld);
            front->left=left;
            pendingqueue.push(left);

        }
              

        int rd;
        //cout<<"Enter Right Child"<<" ";
        cin>>rd;\

        if(rd!=-1)
        {
            Node* right=new Node(rd);
            front->right=right;
            pendingqueue.push(right);        

        }

    }
    return temp;
}
int ans=0;
int largestsumintree(Node* root)
{
	//Base Case
	if(root==NULL)
	{
		return 0;
	}

	//Hypothesis 
	int leftsum=largestsumintree(root->left);
	int rightsum=largestsumintree(root->right);
	ans=max(ans,leftsum+rightsum+root->data);
	return leftsum+rightsum+root->data;

}
int main()
{
	Node* root=takeinput();
	largestsumintree(root);
	cout<<ans;
}