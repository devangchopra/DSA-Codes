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

void ans(Node* root,int s)
{
    if(root==NULL)
        return;
    stack<Node*>s1;//Left
    stack<Node*>s2;//Right
    Node* p=root;
    Node* q=root;
    while(s1.empty()==false or s2.empty()==false or p or q)
    {
        if(p or q)
        {
            if(p)
            {
                s1.push(p);
                p=p->left;
            }
            if(q)
            {
                s2.push(q);
                q=q->right;
            }
        }
        else
        {
            int a=s1.top()->data;
            int b=s2.top()->data;

            if(s1.top()==s2.top())
            {
                break;
            }
            if(a+b==s)
            {
                cout<<a<<" "<<b<<endl;
            }
            if(a+b>s)
            {
                q=s2.top();
                s2.pop();
                //Left most value in right subtree
                q=q->left; //coz q is already right
            }
            else
            {
                p=s1.top();
                s1.pop();
                p=p->right;
            }
        }

    }
}
int main()
{
	Node* root=takeinput();
	int s;
    cin>>s;
    ans(root,s);
}