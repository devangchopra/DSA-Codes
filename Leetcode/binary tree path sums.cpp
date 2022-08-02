class Solution {
public:
    void dfs(TreeNode* root,int t,vector<vector<int>> &ans,vector<int> &output)
    {
        if(root == NULL)
            return;
        if(root->val == t && root->left == NULL && root->right == NULL)
        {
            output.push_back(root->val);
            ans.push_back(output);
            output.pop_back();
            return;
        }
        output.push_back(root->val);
        dfs(root->left, t-root->val, ans, output);
        dfs(root->right, t-root->val, ans, output);
        output.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> output;
        dfs(root, targetSum, ans, output);
        return ans;
        
    }
};