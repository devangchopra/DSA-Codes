class Solution {
public:
    void solve(TreeNode* root,int currmax,int& ans){
        if(!root)
            return;
        if(currmax<=root->val)
            ans++;
        solve(root->left,max(currmax,root->val),ans);
        solve(root->right,max(currmax,root->val),ans);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        solve(root,INT_MIN,ans);
        return ans;
    }
};