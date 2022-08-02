class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) {
			return {};
		}
		vector<vector<int>>ans;
		queue<TreeNode*>Q;
		Q.push(root);
		while (Q.size() != 0) {
			vector<int>temp;
			TreeNode* n;
			int s=Q.size();
			for (int i = 0; i<s; i++) {
				n = Q.front();
				Q.pop();
				temp.push_back(n->val);
				if (n->left) {
					Q.push(n->left);
				}
				if (n->right) {
					Q.push(n->right);
				}
			}
			ans.push_back(temp);
		}
		return ans;
	}
};