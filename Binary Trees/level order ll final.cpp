#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }

};
class BinaryTreeNode
{
    public:

    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

vector<node*> createLLForEachLevel(BinaryTreeNode *root) {
    
    queue<BinaryTreeNode*> q;
    q.push(root);
    //q.push(NULL);
    
    int currlevelRemaining = 1;
    int nxtLevelCount = 0;

    vector<node*> output;
    
    node *currLevelHead = NULL;
    node *currLevelTail = NULL;
    
    while(!q.empty()){
        
        BinaryTreeNode *first = q.front();
        q.pop();
        
        node *newNode = new node(first -> data);
        
        if(currLevelHead == NULL){
            currLevelHead = newNode;
            currLevelTail = newNode;
        }
        
        else{
            currLevelTail -> next = newNode;
            currLevelTail = newNode; 
        }
        
        if(first -> left != NULL){
            q.push(first -> left);
            nxtLevelCount++;
        }
        
        if(first -> right != NULL){
            q.push(first -> right);
            nxtLevelCount++;
        }
        
        currlevelRemaining --;
        
        if(currlevelRemaining == 0){
            output.push_back(currLevelHead);
            currLevelHead = NULL;
            currLevelTail = NULL;
            currlevelRemaining = nxtLevelCount;
            nxtLevelCount = 0;
        }
    }
    return output;
}

/*vector<node*> createLLForEachLevel(BinaryTreeNode* root) {
    
    queue<BinaryTreeNode*> q;
    q.push(root);
    //q.push(NULL);
    
    int Remaining = 1;
    int nxtLevelCount = 0;

    vector<node*> output;
    
    node* Head = NULL;
    node* Tail = NULL;
    
    while(!q.empty()){
        
        BinaryTreeNode* first = q.front();
        q.pop();
        
        node* newNode = new node(first -> data);
        
        if(Head == NULL){
            Head = newNode;
            Tail = newNode;
        }
        
        else{
            Tail -> next = newNode;
            Tail = newNode; 
        }
        
        if(first -> left != NULL){
            q.push(first -> left);
            nxtLevelCount++;
        }
        
        if(first -> right != NULL){
            q.push(first -> right);
            nxtLevelCount++;
        }
        
        Remaining --;
        
        if(Remaining == 0){
            output.push_back(Head);
            Head = NULL;
            Tail = NULL;
            Remaining = nxtLevelCount;
            nxtLevelCount = 0;
        }
    }
    return output;
}*/

BinaryTreeNode* takeinput()
{
    int data;
    cin>>data;
    BinaryTreeNode* root=new BinaryTreeNode(data);
    queue<BinaryTreeNode*>q;
    q.push(root);
    while(q.size()!=0)
    {
        BinaryTreeNode* temp=q.front();
        q.pop();
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            BinaryTreeNode* leftnode=new BinaryTreeNode(leftdata);
            q.push(leftnode);
            temp->left=leftnode;
        }
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            BinaryTreeNode* rightnode=new BinaryTreeNode(rightdata);
            q.push(rightnode);
            temp->right=rightnode;
        }
    }
    return root;
}





int main()
{
    BinaryTreeNode* root=takeinput();
    vector<node*>v= createLLForEachLevel(root);
    for(int i=0;i<v.size();i++)
    {
        node* h=v[i];
        while(h!=0)
        {
            cout<<h->data<<" ";
            h=h->next;
        }       
        cout<<endl;
    }
}