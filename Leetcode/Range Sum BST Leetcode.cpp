// //Approach 1

// class Solution {
// public:
//     void preorder(TreeNode* root,vector<int>& v){
//         if(!root){
//             return;
//         }
//         v.push_back(root->val);
//         preorder(root->left,v);
//         preorder(root->right,v);
//     }
//     int rangeSumBST(TreeNode* root, int low, int high) {
//         //Easy way out is preorder
//         vector<int>v;
//         int sum = 0;
//         preorder(root,v);
//         for(auto& i:v){
//             if(i>=low and i<=high){
//                 sum+=i;
//             }
//         }
//         return sum;
//     }
// };

//Approach 2
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        fun(root, sum, low, high);
        return sum;
    }
    void fun(TreeNode* root, int sum, int low, int high) {
        if (!root) {
            return;
        }
        if (root->val >= low and root->val <= high) {
            sum += root->val;
        }
        if (root->val > low) {
            fun(root->left, sum, low, high);
        }
        if (root->val < high) {
            fun(root->right, sum, low, high);
        }

    }
};