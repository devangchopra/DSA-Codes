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
		int ans = n1+ n2 + carry;
		ListNode* temp = new ListNode(ans % 10);
        ListNode* l1n=NULL;
        ListNode* l2n=NULL;
        if(l1!=NULL){
            l1n=l1->next;
        } 
        if(l2!=NULL){
            l2n=l2->next;
        }

		ListNode* fa = fxn(l1n, l2n, ans / 10);
		temp->next = fa;
		return temp;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode* temp = fxn(l1, l2, carry);
		return temp;
	}
};