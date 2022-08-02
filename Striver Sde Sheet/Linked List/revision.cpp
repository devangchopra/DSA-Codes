#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* takeinput(){
    int data;
    cout<<"Enter Head"<<endl;
    cin>>data;
    Node* head=new Node(data);
    Node* temp=head;
    //for traversal
    while(data!=-1){
        cout<<"Enter Data"<<endl;
        cin>>data;
        if(data==-1){
            break;
        }
        Node* n = new Node(data);
        temp->next=n;
        temp=n;
    }
    return head;
}

Node* insertnode(Node* head,int i,int data){
    //Create a new node
    Node* n=new Node(data);
    if(i==0){
        n->next=head;
        head=n;
        return head;
    }
    Node* temp=head;
    int count=0;
    while(temp!=NULL and count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        n->next=temp->next;
        temp->next=n;
    }
    return head;
}

Node* deletea(Node*head, int i){
    int count = 0;
    if(i==0){
        Node* headn=new Node(head->next->data);
        headn->next=head->next->next;
        delete head;
        return headn;
    }
    //finding address
    Node* temp=head;
    while(temp!=NULL and count<i-1){
        temp=temp->next;
        count++;
    }
    //We have the address of i-1
    Node* a=temp->next;
    //i th node
    Node* b=a->next;
    //i+1
    temp->next=b;
    delete a;
    return head;
}

Node* insertRecursively(Node* head,int i,int data){
    if(head==NULL)
        return NULL;
    if(i==0){
        Node* temp=new Node(data);
        temp->next=head;
        return temp;
    }
    
    if(i==1){
        Node* temp=new Node(data);
        temp->next=head->next;
        head->next=temp;
        return head;
    }
    insertRecursively(head->next,i-1,data);    
    return head;
}

Node* middleNode(Node* head) {
	Node* slow = head;
	Node* fast = head;
	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* mergeTwoLists(Node* h1, Node* h2) {
	Node* fh;
	Node* ft;
	if (h1 == NULL) {
		return h2;
	}
	if (h2 == NULL) {
		return h1;
	}
	if (h1->data > h2->data) {
		fh = h2;
		ft = h2;
		h2 = h2->next;
	}
	else {
		fh = h1;
		ft = h1;
		h1 = h1->next;
	}
	while (h1 != NULL and h2 != NULL) {
		if (h1->data > h2->data) {
			ft->next = h2;
			ft = h2;
			h2 = h2->next;
		}
		else {
			ft->next = h1;
			ft = h1;
			h1 = h1->next;
		}
	}
	if (h1) {
		ft->next = h1;
	}
	if (h2) {
		ft->next = h2;
	}
	return fh;
}

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
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return head;
}

int main() {
	//Static Creation
	//Static Memory is allocated at compile time i.e. before execution
	// Node n1(1);
	// Node* head = &n1;
	// Node n2(2);
	// n1.next = &np;

	// Node* n1 = new Node(10);
	// Node* n2 = new Node(20);
	// Node* n3 = new Node(30);
	// n1->next = n2;
	// n2->next = n3;
	// Node* head = n1;
	// print(n1);
    Node* head=takeinput();
    head = reverseIterative(head);
    print(head);
    
}                                      
 



