Node* reverseRecurison(Node* head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}
	Node* sa = reverseRecurison(head->next);
	head->next->next = head;
    //Node->next->next "sa" ka last element hoga...visualize kro 
	head->next = NULL;
	return sa;
}

Node* reverseIterative(Node* head){
        Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    while(curr!=NULL){
        head=curr;
        //Either do this or return prev 
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return head;
}