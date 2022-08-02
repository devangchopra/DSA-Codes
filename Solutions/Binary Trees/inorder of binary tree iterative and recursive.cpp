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
void iterative_inorder(treenode* root)
{
    if(root==NULL) return;
    stack<treenode*>s;
    treenode* curr=root;
    s.push(curr);
    while(s.size()!=0)
    {
        if(curr==NULL)
        {
            //pop the item
            cout<<s.top()<<" ";
            curr=s.top()->right;
            s.pop();
        }
        else{
            curr=curr->left;
            s.push(curr);
        }
    }

}
void inOrder(treenode *root) 
{ 
    stack<treenode *> s; 
    treenode* curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  NULL) 
        { 
            /* place pointer to a tree node on 
               the stack before traversing 
              the node's left subtree */
            s.push(curr); 
            curr = curr->left; 
        } 
  
        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
  
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        curr = curr->right; 
  
    } /* end of while */
} 
int main()
{
    treenode* root=takeinput();
    inOrder(root);
}

//1 2 3 4 -1 5 6 -1 -1 7 8 -1 -1 -1 -1 -1 -1
//o/p  : 4 2 1 7 5 8 3 6