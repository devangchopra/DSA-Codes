class Solution {
public:
    void deleteNode(ListNode* node) {
        //Never the tail
        node->val=node->next->val;
        node->next=node->next->next;
    }
};