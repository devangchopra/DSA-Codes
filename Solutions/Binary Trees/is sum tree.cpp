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
    pair<int,bool> helper(Node*root)
    {
        if(root == NULL)
        {
            pair<int,bool> output;
            output.first = 0;
            output.second = true;
            return output;
        }
        
        pair<int,bool> leftoutput = helper(root->left);
        pair<int,bool> rightoutput = helper(root->right);

        pair<int,bool> currentoutput;

        currentoutput.first = leftoutput.first + rightoutput.first + root->data;
        currentoutput.second = leftoutput.second && rightoutput.second;


        if(leftoutput.first != 0 and rightoutput.first != 0)
        {
            currentoutput.second = currentoutput.second and (root->data == leftoutput.first + rightoutput.first);
        }
        
    
    return currentoutput;
    }
    bool isSumTree(Node* root)
    {
        if(root == NULL)
        return true;
        else
        {
            pair<int,bool> ans = helper(root);
            return ans.second;
        }
         // Your code here
    }
};
int main()
{
    Node* root=takeinput();
    Solution obj;
    obj.isSumTree(root);
}