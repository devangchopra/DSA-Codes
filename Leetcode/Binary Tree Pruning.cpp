class Solution {
public:
	bool containsOne(TreeNode* root)
	{
		if(!root)
			return false;
		if(root->val == 1)
			return true;

		bool left_hai = containsOne(root->left);
		bool right_hai = containsOne(root->right);

		if(left_hai or right_hai)
			return true;

		return false;
	}
    TreeNode* pruneTree(TreeNode* root) {
    	if(!root)
    		return NULL;

    	if(!containsOne(root))
    	{
    		return NULL;
    	}

    	root->left = pruneTree(root->left);
    	root->right = pruneTree(root->right);

    	return root;
        
    }
};



 