/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	bool solve(TreeNode* root, TreeNode* subRoot) {
		if (!root and !subRoot) {
			return true;
		}
		else if ((root and !subRoot) or (!root and subRoot) or (root->val != subRoot->val)) {
			return 0;
		}

		return solve(root->left, subRoot->left) and solve(root->right, subRoot->right);
	}
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (!root) {
			return false;
		}
		bool opn1 = solve(root, subRoot);
		bool opn2 = isSubtree(root->left, subRoot);
		bool opn3 = isSubtree(root->right, subRoot);

		return opn2 or opn3 or opn1;
	}
};