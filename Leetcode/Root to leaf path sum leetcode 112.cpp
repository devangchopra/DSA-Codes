class Solution {
public:
	vector<int>allSums;
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root) {
			return false;
		}
		helper(root, 0);
		for (auto& i : allSums) {
			cout << i << endl;
		}
		for (auto& i : allSums) {
			if (i == targetSum) {
				return true;
			}
		}
		return false;
	}
	void helper(TreeNode* root, int temp) {
		if (!root) {
			return;
		}
		temp += root->val;
		if (isLeave(root)) {
			allSums.push_back(temp);
			return;
		}		
		helper(root->left, temp);
		helper(root->right, temp);
		return;
	}
	bool isLeave(TreeNode* root) {
		if (root->left == NULL and root->right == NULL) {
			return true;
		}
		return false;
	}
};