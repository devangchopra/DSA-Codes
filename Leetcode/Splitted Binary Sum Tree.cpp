class Solution {
	long long int sum = 0;
	long long int maxProd = 0;
public:
	void dfs(TreeNode* root)
	{
		if (!root)
			return;
		dfs(root->left);
		dfs(root->right);

		sum += root->val;
	}

	int helper(TreeNode* root)
	{
		if (!root)
			return 0;

		int left_ans = helper(root->left);
		int right_ans = helper(root->right);

		int path_ans = left_ans + right_ans + root->val;

		maxProd = max(maxProd, (path_ans * (sum - path_ans)));

		return path_ans;
	}
	int maxProduct(TreeNode* root) {

		dfs(root);
		//For sum
		helper(root);
		//For mx product
		return maxProd % 1000000007;
	}
}


//Splitted binary tree sum