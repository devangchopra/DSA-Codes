class Solution {
public:
	vector<string>allFormations;
	string smallestFromLeaf(TreeNode* root) {
		if (!root) {
			return "";
		}
		string temp = "";
		helper(root, temp);
		return *min_element(allFormations.begin(), allFormations.end());
	}
	void helper(TreeNode* root, string temp) {
		if (!root) {
			return;
		}
		temp.push_front(root->val);
		if (isLeave(root)) {
			allFormations.push_back(temp);
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