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
class Solution
{
    public:
    void  inorder(Node* root,vector<int>&v)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int>p;
        inorder(root,p);
        /*for(auto it:p)
        {
            cout<<it<<" ";
        }
        cout<<endl;*/
        cout<<p[p.size()-K];
        return p[p.size()-K];
    }
};
int main()
{
    Solution obj;
    Node* roo=takeinput();
    int k;
    cin>>k;
    obj.kthLargest(roo,k);
}