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
   cin>>data;
   queue<TreeNode*>pendingnodes;
   TreeNode* root=new TreeNode(data);
   pendingnodes.push(root);

   while(pendingnodes.size()!=0)
   {
       TreeNode* front=pendingnodes.front();
       pendingnodes.pop();
       int childnum;
       cin>>childnum;
       for(int i=0;i<childnum;i++)
       {
           int data;
           cin>>data;
           TreeNode* temp=new TreeNode(data);
           front->children.push_back(temp);
           pendingnodes.push(temp);
           
       }
    
   }
   return root;
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
    cout<<heightoftree(root);
}