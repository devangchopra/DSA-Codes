
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
class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    vector<int> inorder(Node* root)
    {
    	if(root==NULL)
    	{
    	    vector<int>v;
    	    
    		return v;
    	}
    	vector<int>v;
    	inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
        return v;
    }
    bool isIsomorphic(Node *root1,Node *root2)
    {
    //add code here.
        vector<int> v1=inorder(root1);
        vector<int> v2=inorder(root2);
        reverse(v1.begin(),v2.end());
        bool x=true;
        if(v1.size()!=v2.size())
        {
            return false;
        }
        else
        {
            for(int i=0;i<v1.size();i++)
            {
                if(v1[i]!=v2[i])
                {
                    x=false;
                    break;
                }
            }
        }
        return x;
    }
};
int main()
{
    Node* root1=takeinput();
    Node* root2=takeinput();
    Solution obj;
    obj.isIsomorphic(root1,root2);

}