class Solution {
	unordered_set<long long int> s;
public:
	bool findTarget(TreeNode* root, long long int k) {
		if (!root)
			return false;
		if (s.count(k - root->val))
			return true;
		s.insert(root->val);
		return findTarget(root->left, k) || findTarget(root->right, k);
	}
};




