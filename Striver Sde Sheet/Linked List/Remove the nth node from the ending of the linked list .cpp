class Solution {
public:
	ListNode* deletea(ListNode* head, int index) {
		if (index == 0) {
			ListNode* n = head->next;
			delete head;
			return n;
		}
		ListNode* temp = head;
		int count = 0;
		while (temp != NULL and count < index - 1) {
			temp = temp->next;
			count++;
		}
		//We have address of i-1;
       
		ListNode* a = temp->next;
		//i
		ListNode* b = a->next;
		//i+1
		temp->next = b;
		delete a;
		return head;
	}
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int size = 0;
		ListNode* temp = head;
		while (temp != NULL) {
			temp = temp->next;
			size++;
		}
		int index = (size - n);
		head = deletea(head, index);
		return head;
	}
};