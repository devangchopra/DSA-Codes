class Solution {
public:
    vector<int>ans;
    void fxn(TreeNode* root){
        if(!root){
            return;
        }
        fxn(root->left);
        fxn(root->right);
        ans.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        fxn(root);
        return ans;
    }
};