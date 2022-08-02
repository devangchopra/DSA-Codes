//Method 1 : 
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
	bool isPalindrome(ListNode* head) {
		string x = "";
		ListNode* temp = head;
		while (temp != NULL) {
			x.push_back(temp->val);
			temp = temp->next;
		}
		string y = x;
		reverse(y.begin(), y.end());
		if (x == y) {
			return true;
		}
		return false;
	}
};

//Method 2 : 
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
	ListNode* fxn(ListNode* head) {
		if (!head) {
			return NULL;
		}
		ListNode* curr = head;
		ListNode* prev = NULL;
		ListNode* next = NULL;
		while (curr) {
            head=curr;
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return head;
	}
	bool isPalindrome(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		//We are consdering the left mid : even and odd is already safe
		while (fast->next and fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		slow->next = fxn(slow->next);
		slow = slow->next;
		ListNode* temp = head;
		while (temp and slow) {
			if (temp->val == slow->val) {
				temp = temp->next;
				slow = slow->next;
			}
			else {
				return false;
			}
		}
		return true;
	}
};