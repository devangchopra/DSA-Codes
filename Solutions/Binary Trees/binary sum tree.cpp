class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node* root)
    {
        if(root==NULL) return 0; 
        int left=solve(root->left);
        int right=solve(root->right);
        int temp=root->data;
        root->data=left+right;
        return left+right+temp;
    }
    void toSumTree(Node *node)
    {
        solve(node);
        
    }
};