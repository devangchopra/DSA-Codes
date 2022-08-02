#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
    	//Base Condition
    	if(root==NULL)
    	{
    		return true;
    	}
        
        bool isleft=isUnivalTree(root->left);
        bool isright=isUnivalTree(root->right);

        if(isleft and isright)
        {
        	//Check
        	if(root->left and root->right)
        	{
        		if(root->left->val==root->val and root->right->val==root->val)
        		{
        			return true;
        		}
        	}
        	else if(root->left)
        	{
        		if(root->left->val==root->val)
        		{
        			return true;
        		}
        	}
        	else if(root->right)
        	{
        		if(root->right->val==root->val)
        		{
        			return true;
        		}
        	}
        	else if(root)
        	{
        		return true;
        	}

        }

        return false;
    }
};