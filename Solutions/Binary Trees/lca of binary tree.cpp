class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL)
        {
            return NULL;
        }
       //Your code here 
       if(root->data==n1 or root->data==n2)
       {
           return root;
       }
       
       Node* leftans=lca(root->left,n1,n2);
       Node* rightans=lca(root->right,n1,n2);
       
       if(leftans==NULL and rightans!=NULL)
       {
         return rightans;
       }
       if(leftans!=NULL and rightans!=NULL)
       {
           return root;
       }
       if(leftans!=NULL and rightans==NULL)
       {
           return leftans;
       }
       else
       {
           return NULL;
       }
       
       
    }
};