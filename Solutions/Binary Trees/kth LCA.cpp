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
vector<int>* RootToNodePath(Node* root,int a)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a)
    {
        vector<int>* v=new vector<int> ();
        v->push_back(root->data);
        return v;
    }
    vector<int>* leftpath=RootToNodePath(root->left,a);
    if(leftpath!=NULL)
    {
        leftpath->push_back(root->data);
        return leftpath;   
    }
    vector<int>* rightpath=RootToNodePath(root->right,a);
    if(rightpath!=NULL)
    {
        rightpath->push_back(root->data);
        return rightpath;
    }
    else
    {
        return NULL;
    }
    

}
int kthLca(Node* root,int a,int b,int k)
{
    vector<int>* RootToNodePath_a=new vector<int>();
    vector<int>* RootToNodePath_b=new vector<int>();
    RootToNodePath_a=RootToNodePath(root,a);
    RootToNodePath_b=RootToNodePath(root,b);

    int count=1;
    int i=0;
    int j=0;
    while(i<RootToNodePath_b->size() and j<RootToNodePath_a->size())
    {
        if(count==k)
        {
            break;
        }
        if(RootToNodePath_a->at(i)==RootToNodePath_b->at(j))
        {
            count++;
            i++;
            j++;
        }
        i++;
        j++;
    }
    if(count==k)
    {
        return RootToNodePath_a->at(k);
    }
    else{
        return -1;
    }
}

int main()
{
	Node* root=takeinput();
    int a,b;
    cin>>a>>b;
    int k;
    cin>>k;
    cout<<kthLca(root,a,b,k);
}