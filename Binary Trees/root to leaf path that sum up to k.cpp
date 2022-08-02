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
    queue<treenode*>q;
    treenode* root=new treenode(data);
    q.push(root);
    while(q.size()!=0)
    {
        treenode* temp=q.front();
        q.pop();
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            treenode* n=new treenode(ld);
            temp->left=n;
            q.push(n);
        }
        int rd;
        cin>>rd;
        if(rd!=-1)
        {
            treenode* n=new treenode(rd);
            temp->right=n;
            q.push(n);
        }
    }
    return root;
}

void helper(treenode* root, int k, vector<int> v){
    
    if(root == NULL){
        return;
    }
    
    if(root -> left == NULL && root -> right == NULL)
    {
        if(k - root -> data == 0)
        {
            int i = 0;
            while(i < v.size())
            {
                cout << v[i] << " ";
                 i++;
            }
             
            cout << root -> data << endl;
        }
        return;
    }
    
    v.push_back(root -> data);
    helper(root -> left, k - root -> data, v);
    helper(root -> right, k - root -> data, v);

       

}

void rootToLeafPathsSumTo(treenode *root, int k) {
    
    vector<int> v;
    
    helper(root, k, v);
}
int main()
{
    treenode* root=takeinput();
    int k;
    cin>>k;
    rootToLeafPathsSumTo(root,k);
    return 0;
}