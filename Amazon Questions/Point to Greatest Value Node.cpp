/****************************************************************
	Following is the Linked list node structure already written:

	template <typename T>
	class LinkedListNode {
	public:
		T data;
		LinkedListNode* next;
		LinkedListNode* arbit;

		LinkedListNode(T data) {
			this->next = NULL;
			this-> arbit = NULL;
			this->data = data;
		}
	};

*****************************************************************/



LinkedListNode<int>* reverse(LinkedListNode<int>*head)
{
	LinkedListNode<int>*prev = NULL, *current = head, *next;
	while (current != NULL)
	{
		next  = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}
LinkedListNode<int>* populateArbit(LinkedListNode<int>* head)
{
	head = reverse(head);
	LinkedListNode<int> *max = head;
	LinkedListNode<int> *temp = head->next;
	while (temp != NULL)
	{
		temp->arbit = max;
		if (max->data < temp->data)
			max = temp;
		temp = temp->next;
	}
	return reverse(head);
}

