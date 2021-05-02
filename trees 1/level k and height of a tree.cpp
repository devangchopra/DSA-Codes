#include<bits/stdc++.h>
using namespace std;
class TreeNode    //defining our own data type
{
    public:

        int data;
        vector<TreeNode*>children;

    TreeNode(int data)
    {
        this->data=data;
    }
};

TreeNode* takeinput()
{
    int data;
    cout<<"Enter Root Data"<<" ";
    cin>>data;

    TreeNode* root= new TreeNode(data);
    queue<TreeNode*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        TreeNode* front =pendingnodes.front();
        int n;
        cout<<"Enter Number Of Children of"<<front->data<<" ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int k;
            cout<<"Enter "<<i<<"th children"<<" ";
            cin>>k;
            TreeNode* child=new TreeNode(k);
            root->children.push_back(child);
            pendingnodes.push(child);
        }
        pendingnodes.pop();

    } 
    return root;
}
void printtree(TreeNode* root)
{
    TreeNode* temp=root; // staticalyyy allocate
    queue<TreeNode*>pendingnodes;
    pendingnodes.push(temp);
    
    while(pendingnodes.size()!=0)
    {
        TreeNode* front=pendingnodes.front();
        cout<<front->data<<" ";
        pendingnodes.pop();
        for (int i=0;i<front->children.size();i++)
        {
            pendingnodes.push(front->children[i]);
            
        }
        
        
    }
}

void printatlevel_k(TreeNode* root,int k)
{
    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        printatlevel_k(root->children[i],k-1);
    }
}
int heightoftree(TreeNode* root)
{
   int max=0;
   for(int i=0;i<root->children.size();i++)
   {
       
       int temp=heightoftree(root->children[i]);
       if(temp>max)
       {
           max=temp;
       }
   }
   return 1+max;
}
int main()
{
    TreeNode* root=takeinput();
    //printtree(root);
    cout<<heightoftree(root);
}