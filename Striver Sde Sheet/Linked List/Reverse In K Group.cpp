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
	ListNode* fxn(ListNode* head, int k) {
		if (!head) {
			return NULL;
		}
		int size = 0;
		ListNode* temp = head;
		while (temp != NULL) {
			temp = temp->next;
			size++;
		}
		if (k > size) {
			return head;
		}
		ListNode* curr = head;
		ListNode* prev = NULL;
		ListNode* next = NULL;

		int count = 0;
		//reverse in k group
		//every k subset should be reversed
		while (curr != NULL and count < k) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;
		}
		if (next != NULL) {
			head->next = fxn(next, k);
		}
		return prev;
		//visualize it
        //head prev bn jaeg
	}
	ListNode* reverseKGroup(ListNode* head, int k) {


		head = fxn(head, k);
		return head;


	}
};





