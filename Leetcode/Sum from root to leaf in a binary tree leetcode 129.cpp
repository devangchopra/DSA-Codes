class Solution {
public:
    int total;
    int sumNumbers(TreeNode* root) {
        total = 0;
        helper(root, 0);
        return total;
    }
    void helper(TreeNode* root, int temp) {
        if (!root) {
            return;
        }
        temp = temp * 10 + root->val;
        if (isLeave(root)) {
            total += temp;
            return;
        }
        helper(root->left, temp);
        helper(root->right, temp);
    }
    bool isLeave(TreeNode* root) {
        if (root->left == NULL and root->right == NULL) {
            return true;
        }
        return false;
    }
};