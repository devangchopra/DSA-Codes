class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
        {
            vector<vector<int>>v;
            return v;
        }
        vector<vector<int>>v;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0)
        {
            vector<int>s;
            int n=q.size();
            for(int i=1;i<=n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                s.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            v.push_back(s);
        }
        return v;
    }
};