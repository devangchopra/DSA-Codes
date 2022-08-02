class Solution {
public:
    vector<int>ans;
    void fxn(TreeNode* root){
        
        if(!root){
            return;
        }
        ans.push_back(root->val);
        fxn(root->left);
        fxn(root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        fxn(root);
        return ans;
        
    }
};