//DFS:
class Solution {
public:
	void fxn(TreeNode* root, int* ans) {
		if (!root) {
			return;
		}
		if (root->left != NULL) {
			if (root->left->left == NULL and root->left->right == NULL) {
				*ans = *ans + root->left->val;
			}
		}

		fxn(root->left, ans);
		fxn(root->right, ans);
		return;
	}


	int sumOfLeftLeaves(TreeNode* root) {
		if (!root) {
			return 0;
		}
		if (root->left == NULL and root->right == NULL) {
			return 0;
		}
		int ans = 0;
		fxn(root, &ans);
		return ans;
	}
};

//BFS:
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root) {
			return 0;
		}
		if (root->left == NULL and root->right == NULL) {
			return 0;
		}

		queue<TreeNode*>q;
		q.push(root);
		int ans = 0;
		while (q.empty() == false) {
			auto curr = q.front();
			q.pop();

			if (q.front() == NULL) {
				q.pop();
				//NULL implies that this node is the left node
				if (curr->left == NULL and curr->right == NULL) {
					ans += curr->val;
				}
			}
			if (curr->left) {
				q.push(curr->left);
				q.push(NULL);
			}
			if (curr->right) {
				q.push(curr->right);
			}
		}
		return ans;
	}

};