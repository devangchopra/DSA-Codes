class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        //Base Case
        if(head==NULL or head->next==NULL){
            return head;
        }
        //Recursive Call
        ListNode* n=reverseList(head->next);

        //Small Work
        head->next->next=head;
        head->next=NULL;
        return n;
    }
};


//Space usage is same
//But not explicit
//Implicitly
