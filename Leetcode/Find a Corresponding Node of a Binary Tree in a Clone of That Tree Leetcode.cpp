//Not considering the multiple entries yet

class Solution {
public:
    TreeNode* temp;
    void fxn(TreeNode* root, int value) {
        if (!root) {
            return;
        }
        if (root->val == value) {
            temp = root;
            return;
        }
        fxn(root->left, value);
        fxn(root->right, value);
        return;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        //Cloned tree and the target tree are the same
        //diff addresses
        //Follow up: Multiple allowed ?

        //traversal
        int value =  target->val;
        fxn(cloned, value);
        return temp;
    }
};




//Follow up : 

class Solution {
public:
    TreeNode* temp;
    void fxn(TreeNode* root, TreeNode* target) {
        if (!root) {
            return;
        }
        if (root->val == target->val) {
            bool isit = true;
            if ((root->left and target->left and root->left->val != target->left->val)) {
                isit = false;
            }
            if ((root->right and target->right and root->right->val != target->right->val)) {
                isit = false;
            }
            if (isit) {
                temp = root;
                return;
            }
        }
        fxn(root->left, target);
        fxn(root->right, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        fxn(cloned, target);
        return temp;
    }
};