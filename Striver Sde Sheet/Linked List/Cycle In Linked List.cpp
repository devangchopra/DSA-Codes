//Method 1 : 
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
	bool hasCycle(ListNode *head) {
		unordered_map<ListNode*, bool>m;
		bool ans = false;
		ListNode* temp = head;
		while (temp != NULL) {
			if (m.find(temp) == m.end()) {
				m.insert({temp, true});
			}
			else {
				ans = true;
				break;
			}
            temp=temp->next;
		}
		return ans;
	}
};

//Method 2 : 
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
	bool hasCycle(ListNode *head) {
		if (!head) {
			return false;
		}
		ListNode* p = head;
		ListNode* q = head;
		bool ans = false;
		//FLoyd Warshall Algorithm
		while (p and q and q->next) {
			p = p->next;
			q = q->next->next;
			if (p == q) {
				ans = true;
				break;
			}
		}
		return ans;
	}
};