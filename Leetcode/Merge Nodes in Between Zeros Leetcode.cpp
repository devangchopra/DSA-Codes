class Solution {
public:
	ListNode* mergeNodes(ListNode* head) {
		vector<int>values;
		ListNode* temp = head;
		while (temp != NULL) {
			if (temp->val != 0) {
				int ans = 0;
				while (temp->val != 0) {
					ans += temp->val;
					temp = temp->next;
				}
				values.push_back(ans);
			}
			temp = temp->next;
		}
		ListNode* ans = new ListNode(values[0]);
		ListNode* temp2 = ans;
		for (int i = 1; i < values.size(); i++) {
			ListNode* n = new ListNode(values[i]);
			temp2->next=n;
			temp2=n;
		}
		return ans;

	}
};