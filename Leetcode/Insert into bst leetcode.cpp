//Brute Force Naive Approach

class Solution {
public:
	vector<int>v;
	void solve(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		v.push_back(root->val);
		solve(root->left);
		solve(root->right);
	}
	TreeNode* buildBST(vector<int> &nums, int l, int r)
	{
		if (l > r)
			return NULL;
		int mid = (l + r) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left  = buildBST(nums, l, mid - 1);
		root->right = buildBST(nums, mid + 1, r);
		return root;
	}
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		v.push_back(val);
		sort(v.begin(), v.end());
		//Create a bst from sorted array
		return buildBST(v, 0, v.size() - 1);
	}
};

