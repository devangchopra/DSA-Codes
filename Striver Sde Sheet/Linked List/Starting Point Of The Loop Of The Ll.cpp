/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		//Floyd Warshall
		ListNode* p = head;
		ListNode* q = head;
		ListNode* a = NULL;
		while (p and q and q->next) {
			p = p->next;
			q = q->next->next;
			if (p == q) {
				a = p;
				break;
			}
		}
		//a is the floyd point
		if (a) {
			ListNode* temp = head;
			while (temp != a) {
				temp = temp->next;
				a = a->next;
			}
			return a;
		}
		return NULL;
	}
};