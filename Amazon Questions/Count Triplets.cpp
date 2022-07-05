/***************************************
 
    Following is the Node class already written.

    class Node 
    {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data) 
        {
            next = NULL; prev=NULL;
            this->data = data;
        }

        ~Node() 
        {
            if (next != NULL)
            {
                delete next;
            }
        }
    };
 
***************************************/

int countAllTripletSum(Node *head, int x){
    // Write your code here.

    //Step 1 : Find the end node and the number of the nodes
    Node* tail = head;
    int count  = 1;

    while(tail!=NULL and tail->next!=NULL){
        tail = tail->next;
        count++;
    }

    if(count <=2){
        //no triplet can be formed
        return 0;
    }

    //Step 2 : Use Two Pointer Approach
    int final_ans = 0;

    Node* temp=head;

    while(temp!=tail){
        //till we reach the end node
        int currSum = x - temp->data;

        Node* start = temp->next;
        Node* end = tail;

        //We are gonna search in this group

        while(start!=end and start->prev!=end) {            

            //start->prev != end :: m>n :: start goes ahead of end
            //dry run

            if((start->data + end->data) == currSum){
                final_ans++;
                start = start->next;
                end = end->prev;
            }

            else if((start->data + end->data) > currSum){
                //sorted
                end = end->prev;                
            }

            else{
                start = start->next;
            }
        }

        temp=temp->next;
    }

    return final_ans;
}