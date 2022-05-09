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
	int fxn(TreeNode* root, int* ans) {
		if (!root) {
			return 0;
		}
		//get the longestUniValuePath from left as well as right
		int left = fxn(root->left, ans);
		int right = fxn(root->right, ans);

		int leftCheck = 0, rightCheck = 0;
		if (root->left and root->val == root->left->val) {
			leftCheck += left + 1;
		}
		if (root->right and root->val == root->right->val) {
			rightCheck += right + 1;

		}

		*ans = max(*ans, leftCheck + rightCheck);
		//bcoz i want to check maximum value at each node
		return max(leftCheck, rightCheck);
		//because maximum +1 would result in longest uni value path
	}
	int longestUnivaluePath(TreeNode * root) {
		int ans = 0;
		fxn(root, &ans);
		return ans;
	}

};