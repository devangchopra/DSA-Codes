class Solution {
public:
	string s = "";
	void solve(TreeNode* root, vector<string>&v) {
		if (!root) {
			return;
		}
		s.push_back(root->val + '0');
		if (root->left == nullptr and root->right == nullptr) {
			v.push_back(s);
			s.pop_back();
			return;
		}
		solve(root->left, v);
		solve(root->right, v);
		s.pop_back();
		return;

	}
	int sumRootToLeaf(TreeNode* root) {
		vector<string>v;
		solve(root, v);
		int ans = 0;
		for (auto& i : v) {
			ans += stoi(i, 0, 2);
		}
		return ans;

	}
};