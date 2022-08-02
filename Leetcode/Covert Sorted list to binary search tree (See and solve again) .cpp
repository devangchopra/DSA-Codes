/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
/*              // this is the code i submitted
#include<bits/stdc++.h>
using namespace std;
TreeNode* HeightBST(ListNode* head, ListNode* tail){
        if(head==tail)
        return NULL;
        ListNode* F=head;
        ListNode* S=head;
        while(F != tail && F->next != tail){
            S=S->next;
            F=F->next->next;
        }
        TreeNode* root=new TreeNode(S->val);
        root->left=HeightBST(head,S);
        root->right=HeightBST(S->next,tail);
        return root;
    }
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
            return HeightBST(head,NULL);
    }
};
*/