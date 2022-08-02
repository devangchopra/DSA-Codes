class Solution {
public:
	ListNode* mid(ListNode* head, ListNode* tail) {
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* prev = NULL;

		while (fast != tail and fast!=tail->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		return prev;
	}
	TreeNode* build(ListNode* head, ListNode* tail) {
		if (head == tail) {
			TreeNode* node = new TreeNode(head->val);
			return node;
		}
		ListNode* midnode = mid(head, tail);
		TreeNode* node = new TreeNode(midnode->next->val);
		if (tail == head->next) {

			node->left = new TreeNode(midnode->val);
			return node;
		}
		node->left = build(head, midnode);
		node->right = build(midnode->next->next, tail);
		return node;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) {
			return NULL;
		}
		ListNode* tail = head;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		TreeNode* node = build(head, tail);
		return node;

	}
};