class Solution {
public:
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int>ans;

		ListNode* temp = head;
		stack<pair<ListNode*, int>>s;
		int index = 0;

		while (temp != NULL) {
			ans.push_back(0);

			while (s.empty() == false and s.top().first->val < temp->val) {
				ans[s.top().second] = temp->val;
				s.pop();
			}
			s.push({temp, index});
			index++;
			temp = temp->next;
		}
		return ans;
	}
};