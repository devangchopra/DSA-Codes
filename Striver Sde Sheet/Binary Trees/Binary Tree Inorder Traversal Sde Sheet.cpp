class Solution {
public:
    void fxn(TreeNode* root,vector<int>& ans){
        if(!root){
            return;
        }
        fxn(root->left,ans);
        ans.push_back(root->val);
        fxn(root->right,ans);
        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        fxn(root,ans);
        return ans;
    }
};