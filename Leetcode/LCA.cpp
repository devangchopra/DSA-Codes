class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         
        if(!root)
            return NULL;
        
        if(root->val == p->val or root->val==q->val)
        {
            return root;
        }
        
        //Give me the lca
        TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans = lowestCommonAncestor(root->right,p,q);
        
        if(leftans ==NULL and rightans == NULL)
        {
            return NULL;
        }
        
        else if(leftans!=NULL and rightans==NULL)
        {
            return leftans;
        }
        
        else if(rightans!=NULL and leftans==NULL)
        {
            return rightans;
        }
        else
        {
            return root;
        }
        
    }
};
