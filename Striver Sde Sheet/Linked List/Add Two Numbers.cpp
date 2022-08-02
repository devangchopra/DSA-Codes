//Verrrryyy important : NULL Access
class Solution {
public:
	ListNode* fxn(ListNode* l1, ListNode* l2, int carry) {
		if (l1 == NULL and carry == 0) {
			return l2;
		}
		if (l2 == NULL and carry == 0) {
			return l1;
		}
		int n1 = 0, n2 = 0;
		if (l1 != NULL) {
			n1 = l1->val;
		}
		if (l2 != NULL) {
			n2 = l2->val;
		}
		int ans = n1 + n2 + carry;
		ListNode* n = new ListNode(ans % 10);
		ListNode* ll1 = NULL;
        ListNode* ll2 = NULL;
		if (l1 != NULL) {
			ll1 = l1->next;
		}
		if (l2 != NULL) {
			ll2 = l2->next;
		}
		n->next = fxn(ll1, ll2, ans / 10);
		return n;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ans = fxn(l1, l2, 0);
		return ans;
	}
};