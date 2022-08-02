class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool helper(Node* root,int min = INT_MIN , int max=INT_MAX)
    {
        if(root==NULL) return true;
        
        if(root->data<min or root->data>max) return false;
        
        bool isleftok=helper(root->left,min,root->data-1);
        bool isrightok=helper(root->right,root->data,max);
        return isleftok and isrightok;
    }
    bool isBST(Node* root) 
    {
        // Your code here
         if(root==NULL)
         {
             return true;
         }
        return helper(root);
    }
};
