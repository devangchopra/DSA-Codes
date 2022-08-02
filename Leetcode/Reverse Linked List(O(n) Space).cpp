class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if(!head)
			return NULL;
		stack<int>s;
		ListNode* temp = head;
		while (temp != NULL) {
			s.push(temp->val);
			temp = temp->next;
		}
		ListNode* finalhead;
		finalhead = new ListNode(s.top());
		s.pop();
		ListNode* prevHead = finalhead;
		while (s.empty() == false) {
			int t = s.top();
			s.pop();
			ListNode* n = new ListNode(t);
			prevHead->next = n;
			prevHead = n;
		}
		return finalhead;
	}
};